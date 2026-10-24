; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-spare-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A360
select_reusable_spare_actor_for_action_clone:
    clc
    bit $ED
    bpl select_reusable_spare_actor_for_action_clone_c2a39c
    .i16
    ldy #$0A00
select_reusable_spare_actor_for_action_clone_c2a368:
    lda a:$E000,Y
    beq select_reusable_spare_actor_for_action_clone_c2a39d
    rep #$20
    stx $00
    cpy $00
    beq select_reusable_spare_actor_for_action_clone_c2a38f
    lda a:$E020,Y
    .a16
    cmp #$0120
    bcc select_reusable_spare_actor_for_action_clone_c2a382
    .a16
    cmp #$FFE0
    bcc select_reusable_spare_actor_for_action_clone_c2a39d
select_reusable_spare_actor_for_action_clone_c2a382:
    lda a:$E022,Y
    .a16
    cmp #$0100
    bcc select_reusable_spare_actor_for_action_clone_c2a38f
    .a16
    cmp #$FFE0
    bcc select_reusable_spare_actor_for_action_clone_c2a39d
select_reusable_spare_actor_for_action_clone_c2a38f:
    tya
    sec
    .a16
    sbc #$0200
    tay
    sep #$20
    .i16
    cpy #$0600
    bcs select_reusable_spare_actor_for_action_clone_c2a368
select_reusable_spare_actor_for_action_clone_c2a39c:
    rtl
select_reusable_spare_actor_for_action_clone_c2a39d:
    sec
    rtl
