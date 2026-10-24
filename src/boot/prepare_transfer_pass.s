; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_91a2 = $91A2
stage_low_transfer_count = $9193

.segment "CODE"
.org $9164
prepare_transfer_pass:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    php
    sei
    ldx a:$0064
    beq prepare_transfer_pass_9188
    lda a:$006C
    beq prepare_transfer_pass_9188
    lda a:$0010
    bne prepare_transfer_pass_9185
    jsr stage_low_transfer_count
    bra prepare_transfer_pass_9188
prepare_transfer_pass_9185:
    jsr boot_91a2
prepare_transfer_pass_9188:
    inc a:$008E
    plp
    dec a:$008E
    plb
    plp
    pld
    rts
