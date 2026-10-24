; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-menu-exception-transfer.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c7d000 = $C7D000

.segment "CODE"
.org $1E8C
call_saved_flag_menu_restoration_callback:
    jsl f:routine_c7d000
