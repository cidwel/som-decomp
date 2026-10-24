; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16

await_next_scene_vblank_through_long_port_read = $45A9

.segment "CODE"
.org $438F
initialize_mode_seven_transition_vram_and_palettes:
    stz a:$2115
    stz a:$2116
    stz a:$2117
    .a8
    lda #$01
    sta $20
    stz $21
    .a8
    lda #$08
    sta a:$4300
    .a8
    lda #$18
    sta a:$4301
    .i16
    ldx #$0021
    stx a:$4302
    stz a:$4304
    .i16
    ldy #$0004
initialize_mode_seven_transition_vram_and_palettes_c643b4:
    .i16
    ldx #$0004
initialize_mode_seven_transition_vram_and_palettes_c643b7:
    lda $20
    sta a:$2118
    inc $20
    dex
    bne initialize_mode_seven_transition_vram_and_palettes_c643b7
    .i16
    ldx #$007C
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    dey
    bne initialize_mode_seven_transition_vram_and_palettes_c643b4
    .i16
    ldx #$3E00
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    .a8
    lda #$80
    sta a:$2115
    stz a:$2116
    stz a:$2117
    .i16
    ldx #$0020
initialize_mode_seven_transition_vram_and_palettes_c643e8:
    stz a:$2119
    stz a:$2119
    dex
    bne initialize_mode_seven_transition_vram_and_palettes_c643e8
    phb
    .a8
    lda #$C6
    pha
    plb
    .i16
    ldx #$6A00
    .i16
    ldy #$0200
initialize_mode_seven_transition_vram_and_palettes_c643fc:
    lda a:$0000,X
    pha
    .a8
    and #$0F
    sta f:$002119
    pla
    lsr
    lsr
    lsr
    lsr
    sta f:$002119
    inx
    dey
    bne initialize_mode_seven_transition_vram_and_palettes_c643fc
    jsr await_next_scene_vblank_through_long_port_read
    .i16
    ldx #$75D0
    .a8
    lda #$00
    sta f:$002121
    lda a:$0000,X
    sta $48
    lda a:$0001,X
    sta $49
    .i16
    ldy #$0010
initialize_mode_seven_transition_vram_and_palettes_c6442c:
    lda a:$0000,X
    sta f:$002122
    lda a:$0001,X
    sta f:$002122
    inx
    inx
    dey
    bne initialize_mode_seven_transition_vram_and_palettes_c6442c
    .a8
    lda #$80
    sta f:$002121
    .i16
    ldx #$75F0
    .i16
    ldy #$0008
initialize_mode_seven_transition_vram_and_palettes_c6444b:
    lda a:$0000,X
    sta f:$002122
    lda a:$0001,X
    sta f:$002122
    inx
    inx
    dey
    bne initialize_mode_seven_transition_vram_and_palettes_c6444b
    plb
    .i16
    ldx #$4000
    stx a:$2116
    .a8
    lda #$01
    sta a:$4300
    .a8
    lda #$18
    sta a:$4301
    .i16
    ldx #$6700
    stx a:$4302
    .a8
    lda #$C6
    sta a:$4304
    .i16
    ldx #$0080
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    .i16
    ldx #$4100
    stx a:$2116
    .i16
    ldx #$0080
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    .i16
    ldx #$4200
    stx a:$2116
    .i16
    ldx #$0080
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    .i16
    ldx #$4300
    stx a:$2116
    .i16
    ldx #$0080
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    .i16
    ldx #$4040
    stx a:$2116
    .i16
    ldx #$00C0
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    .i16
    ldx #$4180
    stx a:$2116
    .i16
    ldx #$0040
    stx a:$4305
    .a8
    lda #$01
    sta a:$420B
    rts
