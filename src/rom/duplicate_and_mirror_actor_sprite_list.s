; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_actor_sprite_list_to_workspace = $ABA9

.segment "CODE"
.org $AB54
duplicate_and_mirror_actor_sprite_list:
    rep #$20
    txa
    lsr
    tax
    phx
    phy
    jsr copy_actor_sprite_list_to_workspace
    ply
    jsr copy_actor_sprite_list_to_workspace
    plx
    phx
    sep #$20
    lda $02
    asl $02
duplicate_and_mirror_actor_sprite_list_c2ab6a:
    pha
    lda a:$C000,X
    bmi duplicate_and_mirror_actor_sprite_list_c2ab76
    .a8
    cmp #$71
    bcc duplicate_and_mirror_actor_sprite_list_c2ab76
    .a8
    lda #$70
duplicate_and_mirror_actor_sprite_list_c2ab76:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
    sta a:$C000,X
    lda a:$C001,X
    bmi duplicate_and_mirror_actor_sprite_list_c2ab89
    .a8
    cmp #$71
    bcc duplicate_and_mirror_actor_sprite_list_c2ab89
    .a8
    lda #$70
duplicate_and_mirror_actor_sprite_list_c2ab89:
    clc
    .a8
    adc #$0F
    .a8
    eor #$FF
    sta a:$C001,X
    lda a:$C003,X
    .a8
    eor #$C0
    sta a:$C003,X
    inx
    inx
    inx
    inx
    pla
    dec
    bne duplicate_and_mirror_actor_sprite_list_c2ab6a
    rep #$20
    pla
    .a16
    ora #$C000
    tax
    rtl
