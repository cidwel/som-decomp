; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-input-owner-slot.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eace9 = $ACE9

.segment "CODE"
.org $A335
register_native_current_task_in_selected_input_owner_slot:
    phd
    php
    rep #$30
    .a16
    and #$0007
    asl
    asl
    asl
    asl
    clc
    adc a:$0092
    pha
    sep #$20
    jsr routine_7eace9
    plx
    sta a:$0001,X
    plp
    pld
    rts
