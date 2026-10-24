; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_c34d = $C34D
current_task_id = $ACE9

.segment "CODE"
.org $8F8F
reserve_highest_free_hdma_channel:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    stx $01
    .i16
    ldx #$0008
reserve_highest_free_hdma_channel_8f9d:
    lda a:$0071,X
    beq reserve_highest_free_hdma_channel_8faf
    dex
    bne reserve_highest_free_hdma_channel_8f9d
    ldx $01
    stz a:$000F,X
    .i16
    ldx #$0000
    bra reserve_highest_free_hdma_channel_8fc2
reserve_highest_free_hdma_channel_8faf:
    phx
    jsr current_task_id
    plx
    sta a:$0071,X
    txa
    dec
    jsr boot_c34d
    txa
    ldx $01
    sta a:$0009,X
reserve_highest_free_hdma_channel_8fc2:
    pla
    pla
    plp
    pld
    rts
