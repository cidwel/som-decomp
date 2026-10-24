; Recovered Secret of Mana USA routine; behaviour documented in docs/event-screen-tile-reload.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F936
reload_screen_character_slot_two_plane_groups:
    sta $6A
    rep #$20
    lda $68
    .a16
    and #$00F8
    asl
    asl
    sta $6C
    lda $68
    .a16
    and #$0007
    asl
    clc
    adc $6C
    asl
    asl
    asl
    asl
    asl
    .a16
    cmp #$2000
    bcc reload_screen_character_slot_two_plane_groups_dbf95a
    clc
    .a16
    adc #$2000
reload_screen_character_slot_two_plane_groups_dbf95a:
    clc
    .a16
    adc #$2000
    sta f:$7E0E7D
    lda $6A
    asl
    tax
    lda f:$D97F35,X
    asl
    asl
    asl
    asl
    clc
    .a16
    adc #$6000
    sta f:$7E0E7F
    .a16
    lda #$0040
    sta a:$4365
    sta a:$4375
    lda f:$7E0E7D
    sta a:$4362
    clc
    .a16
    adc #$0200
    sta a:$4372
    lda f:$7E0E7F
    sta a:$2116
    .i8
    ldx #$40
    stx a:$420B
    clc
    .a16
    adc #$0100
    sta a:$2116
    .i8
    ldx #$80
    stx a:$420B
    sep #$20
    rts
