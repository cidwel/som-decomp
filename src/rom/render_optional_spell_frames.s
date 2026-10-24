; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16

clear_spell_frame_oam_workspace = $4848
expand_and_render_spell_frame_group = $D3F79F

.segment "CODE"
.org $4892
render_optional_spell_frames:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    rep #$20
    lda f:$7ECFF7
    .a16
    and #$000F
    beq render_optional_spell_frames_c148d5
    dec
    asl
    tax
    lda f:$DCFE8A,X
    ldx a:$8436
    sta a:$010E,X
    cmp a:$010C,X
    bcs render_optional_spell_frames_c148bf
    sta a:$010C,X
render_optional_spell_frames_c148bf:
    sep #$20
    jsr clear_spell_frame_oam_workspace
    ldx a:$8436
    jsl f:expand_and_render_spell_frame_group
    lda f:$0000EC
    .a8
    ora #$08
    sta f:$0000EC
render_optional_spell_frames_c148d5:
    plb
    plp
    pld
    rts
