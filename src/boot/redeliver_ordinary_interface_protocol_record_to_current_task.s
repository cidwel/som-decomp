; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-protocol-ordinary.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00ae76 = $AE76
routine_7eace9 = $ACE9
routine_7eb258 = $B258

.segment "CODE"
.org $AE8B
redeliver_ordinary_interface_protocol_record_to_current_task:
    phx
    jsr routine_7eace9
    plx
    jsr routine_7eb258
    bra routine_00ae76
