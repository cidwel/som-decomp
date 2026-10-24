; docs/ui-native-destination-fade-entry.md
.setcpu "65816"
.segment "CODE"
.org $8B05
long_call_prepare_destination_fade:
    jsr $8B09
    rtl
