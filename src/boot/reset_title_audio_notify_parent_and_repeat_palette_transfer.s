; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-palette-worker.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
allocate_transfer_descriptor = $8FC7
append_pending_record = $B258
audio_boot_public_jump = $C30000
current_task_parent_id = $ACD0
receive_with_supplied_delay = $ABE7
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $D54C
reset_title_audio_notify_parent_and_repeat_palette_transfer:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$00F0
    sta f:$001E00
    jsl f:audio_boot_public_jump
    jsr current_task_parent_id
    pha
    jsr allocate_eight_byte_record
    pla
    jsr append_pending_record
reset_title_audio_notify_parent_and_repeat_palette_transfer_d56f:
    ldx a:$030A
    bne reset_title_audio_notify_parent_and_repeat_palette_transfer_d57c
    .i16
    ldx #$0001
    jsr receive_with_supplied_delay
    bra reset_title_audio_notify_parent_and_repeat_palette_transfer_d56f
reset_title_audio_notify_parent_and_repeat_palette_transfer_d57c:
    ldx a:$030A
    .a16
    lda #$0B08
    .a16
    lda #$0002
    jsr allocate_transfer_descriptor
    lda a:$030A
    clc
    .a16
    adc #$0010
    sta a:$0002,X
    .a16
    lda #$0008
    sta a:$0005,X
    sep #$20
    .a8
    lda #$08
    sta a:$000A,X
    .a8
    lda #$7F
    sta a:$0004,X
    rep #$20
    jsr submit_transfer_or_program_hdma
    .i16
    ldx #$0006
    jsr receive_with_supplied_delay
    bra reset_title_audio_notify_parent_and_repeat_palette_transfer_d57c
