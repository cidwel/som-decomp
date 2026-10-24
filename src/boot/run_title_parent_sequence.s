; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258
copy_and_submit_title_tilemap = $CD82
create_and_enqueue_task = $AB88
dispatch_parent_messages = $D17F
fade_parent_display_in = $D20D
fade_parent_display_until_control_exit = $D1DA
release_eight_byte_record = $B1DD

.segment "CODE"
.org $D23E
run_title_parent_sequence:
    phd
    php
    rep #$30
    sep #$20
    .i16
    ldx #$5F12
    .a8
    lda #$7E
    jsr create_and_enqueue_task
    sta a:$0311
    .i16
    ldx #$03A0
    jsr copy_and_submit_title_tilemap
    jsr fade_parent_display_in
    .a8
    cmp #$00
    bne run_title_parent_sequence_d25f
run_title_parent_sequence_d25c:
    jmp run_title_parent_sequence_d2f9
run_title_parent_sequence_d25f:
    lda a:$0316
    bne run_title_parent_sequence_d273
run_title_parent_sequence_d264:
    .i16
    ldx #$0001
    jsr dispatch_parent_messages
    .a8
    cmp #$00
    beq run_title_parent_sequence_d25c
    lda a:$0316
    beq run_title_parent_sequence_d264
run_title_parent_sequence_d273:
    .a8
    lda #$01
    sta f:$001E00
    .a8
    lda #$2D
    sta f:$001E01
    .a8
    lda #$0B
    sta f:$001E02
    .a8
    lda #$0F
    sta f:$001E03
    jsl f:$C30004
    .i16
    ldx #$7FFF
    jsr dispatch_parent_messages
    .a8
    cmp #$00
    beq run_title_parent_sequence_d2f9
    jsr release_eight_byte_record
    jsr allocate_eight_byte_record
    lda a:$0311
    jsr append_pending_record
    .i16
    ldx #$010E
    jsr dispatch_parent_messages
    .a8
    cmp #$00
    beq run_title_parent_sequence_d2f9
    jsr fade_parent_display_until_control_exit
    .a8
    cmp #$00
    beq run_title_parent_sequence_d2f9
    .i16
    ldx #$0000
    jsr copy_and_submit_title_tilemap
    .i16
    ldx #$001E
    jsr dispatch_parent_messages
    .a8
    cmp #$00
    beq run_title_parent_sequence_d2f9
    .a8
    lda #$01
    sta f:$001E00
    .a8
    lda #$2C
    sta f:$001E01
    .a8
    lda #$0F
    sta f:$001E02
    .a8
    lda #$0F
    sta f:$001E03
    jsl f:$C30004
    jsr fade_parent_display_in
    .a8
    cmp #$00
    beq run_title_parent_sequence_d2f9
    .a8
    lda #$01
    sta a:$0317
    .i16
    ldx #$5EAA
    .a8
    lda #$7E
    jsr create_and_enqueue_task
    sta a:$0312
run_title_parent_sequence_d2f9:
    plp
    pld
    rts
