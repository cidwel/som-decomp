; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_transfer_descriptor = $8FC7
boot_b081 = $B081
copy_far_stack_arguments = $C44E
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $886E
prepare_title_auxiliary_hdma:
    phd
    php
    rep #$30
    tsc
    sec
    sbc #$0006
    tcd
    tcs
    sep #$20
    stx $01
    ldx #$0034
    phx
    lda #$7E
    pha
    phy
    jsr boot_b081
    stx $03
    lda #$7F
    pha
    phx
    jsr copy_far_stack_arguments
    rep #$20
    tsc
    clc
    adc #$0008
    tcs
    sep #$20
    lda #$05
    jsr allocate_transfer_descriptor
    rep #$20
    lda $03
    sta a:$0002,X
    ldy $01
    sta a:$0000,Y
    txa
    sta a:$0002,Y
    sep #$20
    lda #$7F
    sta a:$0004,X
    lda #$22
    sta a:$0001,X
    lda #$02
    sta a:$0000,X
    jsr submit_transfer_or_program_hdma
    rep #$20
    tsc
    clc
    adc #$0006
    tcs
    plp
    pld
    rts
