; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

read_union_of_party_controller_bindings = $6B03

.segment "CODE"
.org $6986
cycle_to_next_eligible_unbound_menu_actor:
    sep #$30
    stz a:$1820
    ldy a:$1877
    dey
cycle_to_next_eligible_unbound_menu_actor_c0698f:
    sep #$30
    iny
    .i8
    cpy #$03
    bcc cycle_to_next_eligible_unbound_menu_actor_c06998
    .i8
    ldy #$00
cycle_to_next_eligible_unbound_menu_actor_c06998:
    .i8
    ldx #$00
    lda a:$1820
    inc a:$1820
    .a8
    cmp #$03
    beq cycle_to_next_eligible_unbound_menu_actor_c069e9
    cpy a:$1808
    beq cycle_to_next_eligible_unbound_menu_actor_c0698f
    rep #$30
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda f:$7E0000,X
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne cycle_to_next_eligible_unbound_menu_actor_c0698f
    lda f:$7E0190,X
    .a16
    and #$8000
    bne cycle_to_next_eligible_unbound_menu_actor_c0698f
    sep #$30
    .a8
    lda #$01
    .i8
    cpy #$00
    beq cycle_to_next_eligible_unbound_menu_actor_c069d6
    asl
    .i8
    cpy #$01
    beq cycle_to_next_eligible_unbound_menu_actor_c069d6
    asl
cycle_to_next_eligible_unbound_menu_actor_c069d6:
    pha
    jsr read_union_of_party_controller_bindings
    and $01,S
    tax
    pla
    txa
    .a8
    ora #$00
    bne cycle_to_next_eligible_unbound_menu_actor_c0698f
    .i8
    ldx #$01
    tya
    sta a:$1808
cycle_to_next_eligible_unbound_menu_actor_c069e9:
    rep #$30
    txa
    .a16
    and #$00FF
    rts
