; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-setup.md.
.setcpu "65816"
.smart
.a8
.i16

test_animation_party_radii_and_mark_contact_slot = $17A9

.segment "CODE"
.org $7E39
scan_native58_party_collision_and_mark_party_action_bytes:
    stz $64
    lda a:$002B,X
    sta $46
    lda a:$0032,X
    clc
    adc a:$00A5,X
    sta $4E
    lda a:$001E,X
    asl
    tax
    lda f:$D97F09,X
    .a16
    and #$00FF
    sta $48
    lda f:$D97F0A,X
    .a16
    and #$00FF
    sta $50
    .i16
    ldy #$0000
scan_native58_party_collision_and_mark_party_action_bytes_c27e63:
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0000,X
    .a16
    cmp #$0001
    bne scan_native58_party_collision_and_mark_party_action_bytes_c27eb3
    lda a:$0002,X
    sta $56
    lda a:$0004,X
    sta $5E
    lda a:$0089,X
    .a16
    and #$0003
    inc
    asl
    tax
    lda f:$D97F09,X
    .a16
    and #$00FF
    sta $58
    lda f:$D97F0A,X
    .a16
    and #$00FF
    sta $60
    jsr test_animation_party_radii_and_mark_contact_slot
    bcc scan_native58_party_collision_and_mark_party_action_bytes_c27eb3
    tya
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    sep #$20
    .a8
    lda #$05
    sta a:$0007,X
    sta a:$000A,X
    rep #$20
    sta $64
scan_native58_party_collision_and_mark_party_action_bytes_c27eb3:
    iny
    .i16
    cpy #$0003
    bne scan_native58_party_collision_and_mark_party_action_bytes_c27e63
    ldx $87
    lda $64
    beq scan_native58_party_collision_and_mark_party_action_bytes_c27ec1
    sec
    rts
scan_native58_party_collision_and_mark_party_action_bytes_c27ec1:
    clc
    rts
