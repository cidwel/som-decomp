; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_ae37 = $AE37
receive_with_existing_timer = $ABAD
receive_with_supplied_delay = $ABE7
release_eight_byte_record = $B1DD

.segment "CODE"
.org $AEC4
receive_parent_message_or_cancel:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
receive_parent_message_or_cancel_aecf:
    jsr boot_ae37
    .i16
    cpx #$0000
    beq receive_parent_message_or_cancel_aedc
    jsr receive_with_supplied_delay
    bra receive_parent_message_or_cancel_aedf
receive_parent_message_or_cancel_aedc:
    jsr receive_with_existing_timer
receive_parent_message_or_cancel_aedf:
    .i16
    cpx #$0000
    beq receive_parent_message_or_cancel_af05
    lda a:$0002,X
    sec
    .a8
    sbc #$FE
    bne receive_parent_message_or_cancel_af07
    lda a:$0004,X
    .a8
    cmp #$01
    beq receive_parent_message_or_cancel_aefb
    jsr release_eight_byte_record
    .i16
    ldx #$0000
    bra receive_parent_message_or_cancel_aecf
receive_parent_message_or_cancel_aefb:
    jsr release_eight_byte_record
    .i16
    ldx #$0000
    .a8
    lda #$00
    bra receive_parent_message_or_cancel_af07
receive_parent_message_or_cancel_af05:
    .a8
    lda #$01
receive_parent_message_or_cancel_af07:
    plb
    plp
    pld
    rts
