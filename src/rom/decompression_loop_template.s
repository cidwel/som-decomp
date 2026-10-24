; Copied into the caller's stack and patched by decompress_block.
; The header selects how many of the five LSR instructions are executed.
.setcpu "65816"
.smart
.a8
.i16

read_decompression_token = $C14CC0

.segment "CODE"
.org $4C06
decompression_loop_template:
    lsr a
    lsr a
    lsr a
    lsr a
    lsr a
    clc
    adc #$02
    sta $01
    rep #$20
    tya
    sec
    sbc $03
    phx
    tax
    lda $01
    mvn #$00, #$00             ; patched to destination bank
    plx
    inc a
    sep #$20
next_token:
    plb
    jsl read_decompression_token
    phb
    bne decompression_loop_template
    mvn #$00, #$00             ; patched to source/destination banks
    inc a
    xba
    bra next_token
