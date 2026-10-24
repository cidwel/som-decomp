; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-menu-normal-spans-source.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1E90
restore_native_menu_caller_after_normal_exit:
    pld
    plb
    plp
    rtl
