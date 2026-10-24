; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

clear_actor_motion_and_graphic_state_before_refresh = $94EA
load_actor_map_graphics = $DFD3
load_actor_map_palette = $E022
routine_00bdbb = $BDBB
routine_00e9f4 = $E9F4
routine_00ea3d = $EA3D
routine_01e6a8 = $1E6A8
routine_01e76d = $1E76D
routine_02b01e = $2B01E
set_actor_program_long = $C10020

.segment "CODE"
.org $939C
refresh_actor_graphics_status_and_controller:
    phy
    .a8
    bit #$01
    beq refresh_actor_graphics_status_and_controller_c193d0
    pha
    phx
    jsr clear_actor_motion_and_graphic_state_before_refresh
    sep #$20
    lda a:$E180,X
    jsl f:set_actor_program_long
    plx
    .i16
    cpx #$0600
    bcs refresh_actor_graphics_status_and_controller_c193c3
    phx
    phb
    .a8
    lda #$00
    pha
    plb
    jsl f:routine_01e6a8
    plb
    rep #$10
    plx
refresh_actor_graphics_status_and_controller_c193c3:
    jsr load_actor_map_palette
    jsr load_actor_map_graphics
    jsl f:routine_00ea3d
    sep #$20
    pla
refresh_actor_graphics_status_and_controller_c193d0:
    .a8
    bit #$04
    beq refresh_actor_graphics_status_and_controller_c193e4
    pha
    phx
    stz a:$E069,X
    jsr clear_actor_motion_and_graphic_state_before_refresh
    jsl f:routine_00e9f4
    sep #$20
    plx
    pla
refresh_actor_graphics_status_and_controller_c193e4:
    ply
    .a8
    bit #$02
    bne refresh_actor_graphics_status_and_controller_c193ea
refresh_actor_graphics_status_and_controller_c193e9:
    rts
refresh_actor_graphics_status_and_controller_c193ea:
    rep #$20
    tya
    sep #$20
    xba
    bpl refresh_actor_graphics_status_and_controller_c19463
    jsr clear_actor_motion_and_graphic_state_before_refresh
    .i16
    cpx #$0600
    bcs refresh_actor_graphics_status_and_controller_c193fe
    jsl f:routine_02b01e
refresh_actor_graphics_status_and_controller_c193fe:
    lda a:$E191,X
    bpl refresh_actor_graphics_status_and_controller_c1942f
    stz a:$E067,X
    .i16
    cpx #$0600
    bcs refresh_actor_graphics_status_and_controller_c193e9
    lda a:$E02C,X
    bne refresh_actor_graphics_status_and_controller_c19415
    lda a:$E08C,X
    beq refresh_actor_graphics_status_and_controller_c1942f
refresh_actor_graphics_status_and_controller_c19415:
    stz a:$E02C,X
    stz a:$E08C,X
    phx
    sep #$10
    dec
    .a8
    cmp #$03
    bcc refresh_actor_graphics_status_and_controller_c19425
    .a8
    lda #$02
refresh_actor_graphics_status_and_controller_c19425:
    tax
    stz $D9,X
    jsl f:routine_00bdbb
    rep #$10
    plx
refresh_actor_graphics_status_and_controller_c1942f:
    lda a:$E000
    beq refresh_actor_graphics_status_and_controller_c1943b
    bmi refresh_actor_graphics_status_and_controller_c1943b
    lda a:$E191
    bpl refresh_actor_graphics_status_and_controller_c19462
refresh_actor_graphics_status_and_controller_c1943b:
    lda a:$E200
    beq refresh_actor_graphics_status_and_controller_c19447
    bmi refresh_actor_graphics_status_and_controller_c19447
    lda a:$E391
    bpl refresh_actor_graphics_status_and_controller_c19462
refresh_actor_graphics_status_and_controller_c19447:
    lda a:$E400
    beq refresh_actor_graphics_status_and_controller_c19453
    bmi refresh_actor_graphics_status_and_controller_c19453
    lda a:$E591
    bpl refresh_actor_graphics_status_and_controller_c19462
refresh_actor_graphics_status_and_controller_c19453:
    phx
    rep #$20
    stz $D4
    .a16
    lda #$07FF
    jsl f:routine_01e76d
    rep #$10
    plx
refresh_actor_graphics_status_and_controller_c19462:
    rts
refresh_actor_graphics_status_and_controller_c19463:
    .a8
    bit #$20
    beq refresh_actor_graphics_status_and_controller_c19472
    pha
    xba
    pha
    jsr load_actor_map_palette
    sep #$20
    pla
    xba
    pla
refresh_actor_graphics_status_and_controller_c19472:
    .a8
    bit #$41
    bne refresh_actor_graphics_status_and_controller_c1947b
    xba
    .a8
    bit #$60
    beq refresh_actor_graphics_status_and_controller_c194e9
refresh_actor_graphics_status_and_controller_c1947b:
    .i16
    cpx #$0600
    bcs refresh_actor_graphics_status_and_controller_c19498
    lda a:$E191,X
    .a8
    bit #$41
    bne refresh_actor_graphics_status_and_controller_c1948e
    lda a:$E190,X
    .a8
    bit #$60
    beq refresh_actor_graphics_status_and_controller_c194b5
refresh_actor_graphics_status_and_controller_c1948e:
    lda a:$E08C,X
    bne refresh_actor_graphics_status_and_controller_c19498
    lda a:$E02C,X
    bne refresh_actor_graphics_status_and_controller_c19499
refresh_actor_graphics_status_and_controller_c19498:
    rts
refresh_actor_graphics_status_and_controller_c19499:
    sta a:$E08C,X
    stz a:$E02C,X
    stz a:$E064,X
    stz a:$E062,X
    stz a:$E006,X
    stz a:$E007,X
    phx
    lda a:$E180,X
    jsl f:set_actor_program_long
    plx
    rts
refresh_actor_graphics_status_and_controller_c194b5:
    lda a:$E08C,X
    bne refresh_actor_graphics_status_and_controller_c194bb
refresh_actor_graphics_status_and_controller_c194ba:
    rts
refresh_actor_graphics_status_and_controller_c194bb:
    stz a:$E08C,X
    sta $00
    lda a:$E02C,X
    bne refresh_actor_graphics_status_and_controller_c194ba
    .a8
    lda #$00
    xba
    lda $00
    dec
    .a8
    cmp #$03
    bcc refresh_actor_graphics_status_and_controller_c194d1
    .a8
    lda #$02
refresh_actor_graphics_status_and_controller_c194d1:
    tay
    lda a:$00D9,Y
    beq refresh_actor_graphics_status_and_controller_c194ba
    lda $00
    sta a:$E02C,X
    stz a:$E013,X
    phx
    pla
    pla
    bne refresh_actor_graphics_status_and_controller_c194e6
    .a8
    lda #$01
refresh_actor_graphics_status_and_controller_c194e6:
    sta a:$00D9,Y
refresh_actor_graphics_status_and_controller_c194e9:
    rts
