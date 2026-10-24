; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b0d6 = $B0D6
release_transfer_descriptor = $9066

.segment "CODE"
.org $88CF
release_title_auxiliary_hdma:
    phd
    php
    rep #$30
    sep #$20
    phx
    ldy a:$0002,X
    tyx
    jsr release_transfer_descriptor
    ply
    ldx a:$0000,Y
    jsr boot_b0d6
    plp
    pld
    rts
