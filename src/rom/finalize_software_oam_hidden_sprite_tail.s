; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BCAB
finalize_software_oam_hidden_sprite_tail:
    rep #$30
    ldx $7C
    .a16
    lda #$E0FF
finalize_software_oam_hidden_sprite_tail_c0bcb2:
    cpx a:$0120
    bcs finalize_software_oam_hidden_sprite_tail_c0bcc3
    sta a:$0800,X
    inx
    inx
    inx
    inx
    .i16
    cpx #$01FC
    bcc finalize_software_oam_hidden_sprite_tail_c0bcb2
finalize_software_oam_hidden_sprite_tail_c0bcc3:
    sta a:$0800,X
    lda $7C
    sta a:$0120
    rts
