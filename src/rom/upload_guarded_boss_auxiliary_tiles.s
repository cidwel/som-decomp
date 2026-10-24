; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

upload_boss_frame_entry = $C20009
upload_first_boss_auxiliary_tiles = $9FAA
upload_second_boss_auxiliary_tiles = $A3B0
upload_third_boss_auxiliary_tiles = $A7B6

.segment "CODE"
.org $9579
upload_guarded_boss_auxiliary_tiles:
    sep #$20
    lda f:$7EE060,X
    beq upload_guarded_boss_auxiliary_tiles_c195b4
    bmi upload_guarded_boss_auxiliary_tiles_c19595
    lda f:$7EE061,X
    beq upload_guarded_boss_auxiliary_tiles_c195b4
    .a8
    lda #$00
    sta f:$7EE061,X
    phx
    jsl f:upload_boss_frame_entry
    plx
upload_guarded_boss_auxiliary_tiles_c19595:
    .i16
    cpx #$0600
    beq upload_guarded_boss_auxiliary_tiles_c195ad
    .i16
    cpx #$0800
    beq upload_guarded_boss_auxiliary_tiles_c195a6
    rep #$20
    sep #$10
    brl upload_third_boss_auxiliary_tiles
upload_guarded_boss_auxiliary_tiles_c195a6:
    rep #$20
    sep #$10
    brl upload_second_boss_auxiliary_tiles
upload_guarded_boss_auxiliary_tiles_c195ad:
    rep #$20
    sep #$10
    brl upload_first_boss_auxiliary_tiles
upload_guarded_boss_auxiliary_tiles_c195b4:
    pld
    rep #$30
    jsl f:upload_boss_frame_entry
    rtl
