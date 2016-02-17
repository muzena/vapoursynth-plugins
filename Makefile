include config.mak

PLUGINS = \
	addgrain \
	awarpsharp2 \
	bifrost \
	bilateral \
	bm3d \
	combmask \
	convo2d \
	ctmf \
	d2vsource \
	damb \
	dctfilter \
	deblock \
	delogo \
	dfttest \
	eedi2 \
	ffms2 \
	fft3dfilter \
	fieldhint \
	fillborders \
	flash3kyuu_deband \
	fluxsmooth \
	fmtconv \
	genericfilters \
	histogram \
	imagereader \
	it \
	knlmeanscl \
	lsmashsource \
	msmoosh \
	mvtools \
	nnedi3 \
	rawsource \
	reduceflicker \
	retinex \
	sangnommod \
	scenechange \
	scrawl \
	scxvid \
	ssiq \
	tc2cfr \
	tcanny \
	tcomb \
	tdeintmod \
	templinearapproximate \
	temporalsoften \
	temporalsoften2 \
	tnlmeans \
	vaguedenoiser \
	vautodeint \
	videoscope \
	waifu2x-opt \
	waifu2x-w2xc \
	wwxd \
	yadifmod \
	zimg

plugins := $(libdir)/vapoursynth
dist-packages := $(prefix)/lib/python3/dist-packages

ifeq ($(V), 1)
MAKE = make V=1
else
MAKE = make
endif

define NL


endef


all:
	$(foreach DIR,$(PLUGINS),$(MAKE) -C plugins/$(DIR) $(NL))

install:
	$(INSTALL) -d $(DESTDIR)$(plugins)
	$(INSTALL) -d $(DESTDIR)$(docdir)
	$(INSTALL) -d $(DESTDIR)$(prefix)/share/nnedi3
	$(INSTALL) -d $(DESTDIR)$(dist-packages)

	$(foreach LIB,$(shell ls plugins/*/*.so),$(INSTALL_DATA) $(LIB) $(DESTDIR)$(plugins) $(NL))
	$(foreach SCRIPT,$(shell ls plugins/*/*.py scripts/*.py), \
		$(INSTALL_DATA) $(SCRIPT) $(DESTDIR)$(dist-packages)/vs-$$(basename $(SCRIPT)) $(NL))

	$(INSTALL) -m 755 plugins/d2vsource/d2vscan.pl $(DESTDIR)$(plugins)
	$(INSTALL_DATA) plugins/d2vsource/d2vscan.txt $(DESTDIR)$(docdir)/d2vscan
	$(foreach FILE,$(shell ls plugins/*/readme* plugins/*/README*), \
		$(INSTALL_DATA) $(FILE) $(DESTDIR)$(docdir)/$(shell echo $$(basename $$(dirname $(FILE)))) $(NL))
	$(foreach FILE,$(shell ls scripts/*.txt plugins/flash3kyuu_deband/*.txt), \
		$(INSTALL_DATA) $(FILE) $(DESTDIR)$(docdir) $(NL))

	$(INSTALL_DATA) README.md $(DESTDIR)$(docdir)
	$(INSTALL_DATA) scripts/README.md $(DESTDIR)$(docdir)/scripts.md
	$(INSTALL_DATA) scripts/vsTAAmbk.md $(DESTDIR)$(docdir)
	$(INSTALL_DATA) plugins/rawsource/format_list.txt $(DESTDIR)$(docdir)/rawsource_format_list
	$(INSTALL_DATA) plugins/fmtconv/doc/fmtconv.html $(DESTDIR)$(docdir)
	$(INSTALL_DATA) plugins/fmtconv/doc/colorspace-subsampling.png $(DESTDIR)$(docdir)
	$(INSTALL_DATA) plugins/fmtconv/doc/vapourdoc.css $(DESTDIR)$(docdir)

	$(INSTALL_DATA) model-weights/nnedi3_weights.bin $(DESTDIR)$(prefix)/share/nnedi3

	$(foreach DIR,anime_style_art anime_style_art_rgb photo,\
		$(INSTALL) -d $(DESTDIR)$(plugins)/models/$(DIR) $(NL)\
		$(INSTALL_DATA) model-weights/waifu2x-models/$(DIR)/noise1_model.json $(DESTDIR)$(plugins)/models/$(DIR) $(NL)\
		$(INSTALL_DATA) model-weights/waifu2x-models/$(DIR)/noise2_model.json $(DESTDIR)$(plugins)/models/$(DIR) $(NL)\
		$(INSTALL_DATA) model-weights/waifu2x-models/$(DIR)/scale2.0x_model.json $(DESTDIR)$(plugins)/models/$(DIR) $(NL))
	$(foreach MDL,noise1_model.json noise2_model.json scale2.0x_model.json,\
		$(LN_S) models/anime_style_art/$(MDL) $(DESTDIR)$(plugins)/$(MDL) $(NL))

clean:
	$(MAKE) -f ffmpeg.mak $@
	$(foreach DIR,$(PLUGINS),$(MAKE) -C plugins/$(DIR) clean || true $(NL))

distclean: clean
	$(MAKE) -f ffmpeg.mak $@
	$(foreach DIR,$(PLUGINS),$(MAKE) -C plugins/$(DIR) distclean || true $(NL))
	rm -f config.log config.status config.mak

maintainer-clean: distclean
	rm -rf autom4te.cache plugins/imagereader/libjpeg-turbo/autom4te.cache

config.mak:
	./configure

