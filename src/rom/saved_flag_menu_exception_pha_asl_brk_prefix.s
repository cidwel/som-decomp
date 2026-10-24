; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-menu-exception-prefix.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D000
saved_flag_menu_exception_pha_asl_brk_prefix:
    pha
    asl
    brk $E0
