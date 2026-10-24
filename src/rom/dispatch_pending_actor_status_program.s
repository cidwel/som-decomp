; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

call_actor_status_program_long = $C10024

.segment "CODE"
.org $3F08
dispatch_pending_actor_status_program:
    lda a:$E1FB,X
    .a8
    bit #$08
    beq dispatch_pending_actor_status_program_c03f24
    .a8
    and #$F7
    sta a:$E1FB,X
    lda a:$E1FB,X
    php
    .a8
    lda #$01
    plp
    bmi dispatch_pending_actor_status_program_c03f1e
    inc
dispatch_pending_actor_status_program_c03f1e:
    jsl f:call_actor_status_program_long
    ldx $85
dispatch_pending_actor_status_program_c03f24:
    sep #$20
    rts
