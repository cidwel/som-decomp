; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $ABA9
copy_actor_sprite_list_to_workspace:
    rep #$20
    lda $02
    .a16
    and #$00FF
copy_actor_sprite_list_to_workspace_c2abb0:
    pha
    lda a:$0000,Y
    sta a:$C000,X
    lda a:$0002,Y
    sta a:$C002,X
    inx
    inx
    inx
    inx
    iny
    iny
    iny
    iny
    pla
    dec
    bne copy_actor_sprite_list_to_workspace_c2abb0
    rts
