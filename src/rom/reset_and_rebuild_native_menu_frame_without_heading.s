; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c021f9 = $21F9

.segment "CODE"
.org $2AE3
reset_and_rebuild_native_menu_frame_without_heading:
    stz a:$A200
    jsr routine_c021f9
    rtl
