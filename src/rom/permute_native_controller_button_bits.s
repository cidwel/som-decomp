; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-mapping.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9476
permute_native_controller_button_bits:
    sta $02
    txa
    .a8
    and #$C0
    beq permute_native_controller_button_bits_c0948e
    sta $03
    tya
    eor $02
    and $03
    sta $03
    eor $02
    sta $02
    tya
    eor $03
    tay
permute_native_controller_button_bits_c0948e:
    txa
    .a8
    and #$30
    beq permute_native_controller_button_bits_c094b9
    .a8
    bit #$20
    beq permute_native_controller_button_bits_c094ac
    lda $02
    .a8
    and #$C0
    beq permute_native_controller_button_bits_c094a7
    .a8
    cmp #$C0
    beq permute_native_controller_button_bits_c094a7
    lda $02
    .a8
    eor #$C0
    sta $02
permute_native_controller_button_bits_c094a7:
    txa
    .a8
    bit #$10
    beq permute_native_controller_button_bits_c094b9
permute_native_controller_button_bits_c094ac:
    tya
    .a8
    and #$C0
    beq permute_native_controller_button_bits_c094b9
    .a8
    cmp #$C0
    beq permute_native_controller_button_bits_c094b9
    tya
    .a8
    eor #$C0
    tay
permute_native_controller_button_bits_c094b9:
    txa
    .a8
    and #$0C
    beq permute_native_controller_button_bits_c094f8
    .a8
    bit #$08
    beq permute_native_controller_button_bits_c094e0
    tya
    .a8
    bit #$40
    beq permute_native_controller_button_bits_c094cd
    bit $02
    bmi permute_native_controller_button_bits_c094db
    bpl permute_native_controller_button_bits_c094d1
permute_native_controller_button_bits_c094cd:
    bit $02
    bpl permute_native_controller_button_bits_c094db
permute_native_controller_button_bits_c094d1:
    lda $02
    .a8
    eor #$80
    sta $02
    tya
    .a8
    eor #$40
    tay
permute_native_controller_button_bits_c094db:
    txa
    .a8
    bit #$04
    beq permute_native_controller_button_bits_c094f8
permute_native_controller_button_bits_c094e0:
    lda $02
    .a8
    bit #$40
    beq permute_native_controller_button_bits_c094eb
    tya
    bmi permute_native_controller_button_bits_c094f8
    bpl permute_native_controller_button_bits_c094ee
permute_native_controller_button_bits_c094eb:
    tya
    bpl permute_native_controller_button_bits_c094f8
permute_native_controller_button_bits_c094ee:
    lda $02
    .a8
    eor #$40
    sta $02
    tya
    .a8
    eor #$80
    tay
permute_native_controller_button_bits_c094f8:
    txa
    .a8
    and #$03
    beq permute_native_controller_button_bits_c09519
    lsr
    bcc permute_native_controller_button_bits_c0950a
    lda $02
    .a8
    bit #$03
    beq permute_native_controller_button_bits_c0950a
    .a8
    eor #$03
    sta $02
permute_native_controller_button_bits_c0950a:
    txa
    .a8
    bit #$02
    beq permute_native_controller_button_bits_c09519
    lda $02
    .a8
    bit #$0C
    beq permute_native_controller_button_bits_c09519
    .a8
    eor #$0C
    sta $02
permute_native_controller_button_bits_c09519:
    lda $02
    rts
