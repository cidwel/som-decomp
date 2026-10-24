; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-exit.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $87A1
return_after_ui_scene_button_dispatch:
    rts
