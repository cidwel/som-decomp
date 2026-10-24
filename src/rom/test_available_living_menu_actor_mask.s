; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

read_union_of_party_controller_bindings = $6B03

.segment "CODE"
.org $6B0A
test_available_living_menu_actor_mask:
    jsr read_union_of_party_controller_bindings
    .a8
    eor #$FF
    and f:$C06B46,X
    beq test_available_living_menu_actor_mask_c06b43
    pha
    phx
    rep #$30
    .a16
    and #$0006
    xba
    clc
    .a16
    adc #$E000
    tax
    lda f:$7E0000,X
    tay
    lda f:$7E0190,X
    .a16
    and #$8000
    sta a:$1820
    sep #$30
    plx
    pla
    .i8
    cpy #$01
    bne test_available_living_menu_actor_mask_c06b43
    ldy a:$1821
    .i8
    cpy #$00
    bne test_available_living_menu_actor_mask_c06b43
    .a8
    ora #$00
    rts
test_available_living_menu_actor_mask_c06b43:
    .a8
    lda #$00
    rts
