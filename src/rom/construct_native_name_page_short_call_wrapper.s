; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-name-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c75000 = $C75000

.segment "CODE"
.org $2AA4
construct_native_name_page_short_call_wrapper:
    jsl f:routine_c75000
    rts
