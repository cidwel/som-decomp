; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-cold-menu-bridge-source.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eae28 = $AE28
routine_c00000 = $C00000
routine_c00009 = $C00009
routine_c00012 = $C00012

.segment "CODE"
.org $AF19
enter_boot_menu_after_cold_scheduler_returns:
    jsr routine_7eae28
    jsl f:routine_c00000
    jsl f:routine_c00012
    jml f:routine_c00009
