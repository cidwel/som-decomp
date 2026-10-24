; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16

render_optional_spell_frames_long = $C10034

.segment "CODE"
.org $BCCC
initialize_software_oam_and_optional_spell_frames:
    rep #$30
    .a16
    lda #$0001
    sta $59
    stz $5A
    stz $7C
    stz $7D
    .i16
    ldx #$0200
initialize_software_oam_and_optional_spell_frames_c0bcdc:
    stz a:$0800,X
    inx
    inx
    .i16
    cpx #$0220
    bcc initialize_software_oam_and_optional_spell_frames_c0bcdc
    sep #$20
    lda f:$7ECFF7
    beq initialize_software_oam_and_optional_spell_frames_c0bcf2
    jsl f:render_optional_spell_frames_long
initialize_software_oam_and_optional_spell_frames_c0bcf2:
    rts
