; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

test_available_living_menu_actor_mask = $6B0A

.segment "CODE"
.org $6ADE
choose_other_available_menu_actor:
    sep #$30
    txa
    sta a:$1820
    tya
    cmp a:$1820
    bne choose_other_available_menu_actor_c06aeb
    rts
choose_other_available_menu_actor_c06aeb:
    lda a:$1877
    tax
    jsr test_available_living_menu_actor_mask
    bne choose_other_available_menu_actor_c06afe
    inx
    jsr test_available_living_menu_actor_mask
    bne choose_other_available_menu_actor_c06afe
    lda f:$C06B47,X
choose_other_available_menu_actor_c06afe:
    lsr
    sta a:$1808
    rts
