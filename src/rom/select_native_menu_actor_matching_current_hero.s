; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2955
select_native_menu_actor_matching_current_hero:
    phb
    .a8
    lda #$7E
    pha
    plb
    lda f:$0019FE
    asl
    bne select_native_menu_actor_matching_current_hero_c02962
    inc
select_native_menu_actor_matching_current_hero_c02962:
    .i16
    ldx #$0000
    sta a:$A173
select_native_menu_actor_matching_current_hero_c02968:
    lda $D9,X
    .a8
    and #$7F
    cmp a:$A173
    beq select_native_menu_actor_matching_current_hero_c0297a
    inx
    .i16
    cpx #$0003
    bne select_native_menu_actor_matching_current_hero_c02968
    .i16
    ldx #$0000
select_native_menu_actor_matching_current_hero_c0297a:
    txa
    sta a:$A220
    .a8
    lda #$00
    sta a:$A221
    plb
    rts
