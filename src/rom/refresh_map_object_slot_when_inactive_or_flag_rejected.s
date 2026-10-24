; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-object-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00e00c = $E00C
routine_02c757 = $2C757

.segment "CODE"
.org $EA84
refresh_map_object_slot_when_inactive_or_flag_rejected:
    sep #$20
    lda a:$E000,X
    beq refresh_map_object_slot_when_inactive_or_flag_rejected_c1ea94
    ldy a:$E034,X
    jsl f:routine_02c757
    bcs refresh_map_object_slot_when_inactive_or_flag_rejected_c1ea98
refresh_map_object_slot_when_inactive_or_flag_rejected_c1ea94:
    jsl f:routine_00e00c
refresh_map_object_slot_when_inactive_or_flag_rejected_c1ea98:
    rts
