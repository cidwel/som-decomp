PYTHON ?= python3
CA65 ?= ca65
LD65 ?= ld65
ROM ?= baserom.sfc

.PHONY: setup verify-source build-recovered-rom verify-recovered-rom
setup:
	$(PYTHON) tools/extract_rom_sources.py "$(ROM)"

verify-source:
	$(PYTHON) tools/verify_source.py "$(ROM)" --ca65 "$(CA65)" --ld65 "$(LD65)" --json data/source_build.json

RECOVERED_OUTPUT ?= /tmp/som-recovered-rom
build-recovered-rom:
	$(PYTHON) tools/build_recovered_rom.py --output "$(RECOVERED_OUTPUT)" --ca65 "$(CA65)" --ld65 "$(LD65)"

verify-recovered-rom:
	$(PYTHON) tools/verify_recovered_rom.py "$(ROM)" --build "$(RECOVERED_OUTPUT)" --static --fresh --ca65 "$(CA65)" --ld65 "$(LD65)" --json data/recovered_rom_build_verification.json
