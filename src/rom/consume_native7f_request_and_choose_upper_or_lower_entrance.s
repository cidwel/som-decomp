; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-frame-requests.md.
.setcpu "65816"
.smart
.a8
.i16

draw_boss_frame_random_number = $300B
prepare_boss_loader_resource_expansion = $24C3
publish_native7f_single_mode7_frame_dma_request = $95A0
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $94BE
consume_native7f_request_and_choose_upper_or_lower_entrance:
    lda a:$0364
    beq consume_native7f_request_and_choose_upper_or_lower_entrance_c294cc
    .a16
    lda #$001F
    jsr prepare_boss_loader_resource_expansion
    stz a:$0364
consume_native7f_request_and_choose_upper_or_lower_entrance_c294cc:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0009
    bcc consume_native7f_request_and_choose_upper_or_lower_entrance_c29534
    stz a:$0096,X
    .a16
    lda #$0080
    sta a:$00B0,X
    .a16
    lda #$0110
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0002
    sta a:$000B,X
    .a16
    lda #$0001
    sta a:$00B6,X
    .a16
    lda #$0040
    sta a:$02D5
    .a16
    lda #$0040
    sta a:$02D7
    .a16
    lda #$0010
    jsr draw_boss_frame_random_number
    .a16
    cmp #$0007
    bcs consume_native7f_request_and_choose_upper_or_lower_entrance_c2951e
    ldx $87
    .a16
    lda #$0006
    sta a:$0094,X
    .a16
    lda #$0128
    sta a:$002B,X
    .a16
    lda #$0070
    sta a:$0032,X
    bra consume_native7f_request_and_choose_upper_or_lower_entrance_c29537
consume_native7f_request_and_choose_upper_or_lower_entrance_c2951e:
    ldx $87
    .a16
    lda #$000D
    sta a:$0094,X
    .a16
    lda #$0128
    sta a:$002B,X
    .a16
    lda #$0250
    sta a:$0032,X
    bra consume_native7f_request_and_choose_upper_or_lower_entrance_c29537
consume_native7f_request_and_choose_upper_or_lower_entrance_c29534:
    jsr publish_native7f_single_mode7_frame_dma_request
consume_native7f_request_and_choose_upper_or_lower_entrance_c29537:
    clc
    rts
