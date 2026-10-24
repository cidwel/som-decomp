; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-palette-transition.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C820
update_scene_palette_rgb_offset_and_transition_phase:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$10
    .i16
    ldx #$01FE
    bit $2A
    bvs update_scene_palette_rgb_offset_and_transition_phase_c2c833
    .i16
    ldx #$00FE
update_scene_palette_rgb_offset_and_transition_phase_c2c833:
    rep #$20
    lda a:$010A
    .a16
    and #$001F
    sta $00
    lda a:$010A
    .a16
    and #$03E0
    sta $02
    lda a:$010A
    .a16
    and #$7C00
    sta $04
    lda a:$010C
    bpl update_scene_palette_rgb_offset_and_transition_phase_c2c855
    brl update_scene_palette_rgb_offset_and_transition_phase_c2c892
update_scene_palette_rgb_offset_and_transition_phase_c2c855:
    lda a:$0600,X
    pha
    sep #$20
    .a8
    and #$1F
    clc
    adc $00
    .a8
    cmp #$20
    bcc update_scene_palette_rgb_offset_and_transition_phase_c2c866
    .a8
    lda #$1F
update_scene_palette_rgb_offset_and_transition_phase_c2c866:
    xba
    .a8
    and #$7C
    clc
    adc $05
    bpl update_scene_palette_rgb_offset_and_transition_phase_c2c870
    .a8
    lda #$7C
update_scene_palette_rgb_offset_and_transition_phase_c2c870:
    xba
    rep #$20
    sta $06
    pla
    .a16
    and #$03E0
    clc
    adc $02
    .a16
    cmp #$0400
    bcc update_scene_palette_rgb_offset_and_transition_phase_c2c884
    .a16
    lda #$03E0
update_scene_palette_rgb_offset_and_transition_phase_c2c884:
    ora $06
    sta a:$BE00,X
    dex
    dex
    .i16
    cpx #$0020
    bcs update_scene_palette_rgb_offset_and_transition_phase_c2c855
    bra update_scene_palette_rgb_offset_and_transition_phase_c2c8c8
update_scene_palette_rgb_offset_and_transition_phase_c2c892:
    lda a:$0600,X
    pha
    sep #$20
    .a8
    and #$1F
    sec
    sbc $00
    bpl update_scene_palette_rgb_offset_and_transition_phase_c2c8a1
    .a8
    lda #$00
update_scene_palette_rgb_offset_and_transition_phase_c2c8a1:
    xba
    .a8
    and #$7C
    sec
    sbc $05
    bpl update_scene_palette_rgb_offset_and_transition_phase_c2c8ab
    .a8
    lda #$00
update_scene_palette_rgb_offset_and_transition_phase_c2c8ab:
    xba
    rep #$20
    sta $06
    pla
    .a16
    and #$03E0
    sec
    sbc $02
    bpl update_scene_palette_rgb_offset_and_transition_phase_c2c8bc
    .a16
    lda #$0000
update_scene_palette_rgb_offset_and_transition_phase_c2c8bc:
    ora $06
    sta a:$BE00,X
    dex
    dex
    .i16
    cpx #$0020
    bcs update_scene_palette_rgb_offset_and_transition_phase_c2c892
update_scene_palette_rgb_offset_and_transition_phase_c2c8c8:
    lda a:$0600,X
    sta a:$BE00,X
    dex
    dex
    bne update_scene_palette_rgb_offset_and_transition_phase_c2c8c8
    lda a:$BE20
    sta a:$BE00
    sep #$20
    bit $2A
    bmi update_scene_palette_rgb_offset_and_transition_phase_c2c936
    rep #$20
    lda a:$010C
    .a16
    and #$03E0
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c8fe
    sta $00
    lda a:$010A
    .a16
    and #$03E0
    cmp $00
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c8fe
    lda a:$010A
    clc
    .a16
    adc #$0020
    sta a:$010A
update_scene_palette_rgb_offset_and_transition_phase_c2c8fe:
    sep #$20
    lda a:$010C
    .a8
    and #$1F
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c919
    sta $00
    lda a:$010A
    .a8
    and #$1F
    cmp $00
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c919
    lda a:$010A
    inc
    sta a:$010A
update_scene_palette_rgb_offset_and_transition_phase_c2c919:
    lda a:$010D
    .a8
    and #$7C
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c934
    sta $00
    lda a:$010B
    .a8
    and #$7C
    cmp $00
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c934
    lda a:$010B
    clc
    .a8
    adc #$04
    sta a:$010B
update_scene_palette_rgb_offset_and_transition_phase_c2c934:
    plb
    rtl
update_scene_palette_rgb_offset_and_transition_phase_c2c936:
    sep #$20
    lda a:$010A
    ora a:$010B
    bne update_scene_palette_rgb_offset_and_transition_phase_c2c942
    stz $2A
update_scene_palette_rgb_offset_and_transition_phase_c2c942:
    lda a:$010A
    .a8
    and #$1F
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c950
    lda a:$010A
    dec
    sta a:$010A
update_scene_palette_rgb_offset_and_transition_phase_c2c950:
    lda a:$010B
    .a8
    and #$7C
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c960
    lda a:$010B
    sec
    .a8
    sbc #$04
    sta a:$010B
update_scene_palette_rgb_offset_and_transition_phase_c2c960:
    rep #$20
    lda a:$010A
    .a16
    and #$03E0
    beq update_scene_palette_rgb_offset_and_transition_phase_c2c974
    lda a:$010A
    sec
    .a16
    sbc #$0020
    sta a:$010A
update_scene_palette_rgb_offset_and_transition_phase_c2c974:
    plb
    rtl
