; Recovered Secret of Mana USA boot code. See docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
allocate_transfer_descriptor = $8FC7
append_oneshot_ppu_entry = $C097
boot_b081 = $B081
copy_far_stack_arguments = $C44E
prepare_title_auxiliary_hdma = $886E
submit_transfer_or_program_hdma = $90DA

.segment "CODE"
.org $88E7
prepare_title_buffer_display:
    phd
    php
    rep #$30
    sep #$20
    lda #$78
    sta a:$0056
    lda #$1F
    sta a:$0059
    lda #$38
    sta a:$005C
    lda #$01
    sta a:$005F
    stz a:$0062
    rep #$20
    stz a:$0057
    stz a:$005A
    stz a:$005D
    stz a:$0060
    lda #$0005
    jsr allocate_transfer_descriptor
    stx a:$003A
    lda #$0056
    sta a:$0002,X
    sep #$20
    lda #$7F
    sta a:$0004,X
    lda #$10
    sta a:$0001,X
    lda #$02
    sta a:$0000,X
    jsr submit_transfer_or_program_hdma
    php
    sei
    ldy #$5CFB
    ldx #$004A
    jsr prepare_title_auxiliary_hdma
    ldy #$5CC7
    ldx #$0046
    jsr prepare_title_auxiliary_hdma
    ldy #$5C93
    ldx #$0042
    jsr prepare_title_auxiliary_hdma
    lda #$05
    jsr allocate_transfer_descriptor
    stx a:$0040
    rep #$20
    lda #$5C75
    sta a:$0002,X
    sep #$20
    lda #$7E
    sta a:$0004,X
    lda #$21
    sta a:$0001,X
    lda #$00
    sta a:$0000,X
    jsr submit_transfer_or_program_hdma
    plp
    ldx #$0011
    phx
    lda #$7E
    pha
    ldy #$5C64
    phy
    jsr boot_b081
    stx a:$0054
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
    stx a:$003E
    rep #$20
    lda a:$0054
    sta a:$0002,X
    sep #$20
    lda #$7F
    sta a:$0004,X
    lda #$2D
    sta a:$0001,X
    lda #$00
    sta a:$0000,X
    jsr submit_transfer_or_program_hdma
    ldx #$0011
    phx
    lda #$7E
    pha
    ldy #$5C53
    phy
    jsr boot_b081
    stx a:$0052
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
    stx a:$003C
    rep #$20
    lda a:$0052
    sta a:$0002,X
    sep #$20
    lda #$7F
    sta a:$0004,X
    lda #$27
    sta a:$0001,X
    lda #$00
    sta a:$0000,X
    jsr submit_transfer_or_program_hdma
    lda #$26
    jsr allocate_ppu_register_entry
    lda #$00
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$27
    jsr allocate_ppu_register_entry
    lda #$FF
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$30
    jsr allocate_ppu_register_entry
    lda #$02
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$31
    jsr allocate_ppu_register_entry
    lda #$31
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$2E
    jsr allocate_ppu_register_entry
    lda #$02
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    lda #$23
    jsr allocate_ppu_register_entry
    lda #$30
    sta a:$0002,X
    jsr append_oneshot_ppu_entry
    plp
    pld
    rts
