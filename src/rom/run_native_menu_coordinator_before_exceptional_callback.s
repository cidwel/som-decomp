; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-menu-normal-spans-source.md.
.setcpu "65816"
.smart
.a8
.i16

restore_native_menu_caller_after_normal_exit = $1E90
routine_c00ebf = $C00EBF
routine_c01e94 = $1E94
routine_c01ed1 = $1ED1
routine_c025ad = $25AD
routine_c02781 = $2781
routine_c0281e = $281E
routine_c028a6 = $28A6
routine_c028d9 = $28D9
routine_c02910 = $2910
routine_c02930 = $2930
routine_c02955 = $2955
routine_c029d2 = $29D2
routine_c02b06 = $2B06
routine_c02bd9 = $2BD9

.segment "CODE"
.org $1D97
run_native_menu_coordinator_before_exceptional_callback:
    php
    phb
    phd
    sep #$20
    rep #$10
    phx
    pha
    .i16
    ldy #$0000
    phy
    pld
    lda f:$0019FE
    sta f:$7EA21F
    jsr routine_c02910
    jsr routine_c02955
    jsl f:routine_c00ebf
    pla
    pha
    jsr routine_c0281e
    pla
    rep #$20
    .a16
    and #$00FF
    sep #$20
    tax
    lda f:$C02A60,X
    ply
run_native_menu_coordinator_before_exceptional_callback_c01dca:
    sta f:$7EA202
    sty a:$A22B
    pha
    jsr routine_c02910
    .a8
    lda #$10
    trb a:$A212
    jsr routine_c028a6
    .a8
    lda #$00
    xba
    pla
    asl
    tax
    jsr ($2A7A,X)
    .a8
    lda #$81
    sta f:$004200
    jsr routine_c02930
run_native_menu_coordinator_before_exceptional_callback_c01def:
    lda f:$004212
    .a8
    and #$80
    bne run_native_menu_coordinator_before_exceptional_callback_c01def
run_native_menu_coordinator_before_exceptional_callback_c01df7:
    lda f:$004212
    .a8
    and #$80
    beq run_native_menu_coordinator_before_exceptional_callback_c01df7
    jsr routine_c01e94
    jsr routine_c028d9
    jsr routine_c01ed1
    lda a:$A201
    inc
    sta a:$A201
    .a8
    cmp #$04
    bne run_native_menu_coordinator_before_exceptional_callback_c01e1c
    stz a:$A201
    jsr routine_c02bd9
    jsr routine_c02b06
run_native_menu_coordinator_before_exceptional_callback_c01e1c:
    lda a:$A20A
    .a8
    and #$01
    beq run_native_menu_coordinator_before_exceptional_callback_c01def
    lda a:$A210
    .a8
    cmp #$FF
    beq run_native_menu_coordinator_before_exceptional_callback_c01e30
    sta a:$A202
    jmp run_native_menu_coordinator_before_exceptional_callback_c01dca
run_native_menu_coordinator_before_exceptional_callback_c01e30:
    jsr routine_c02910
    lda a:$A202
    .a8
    cmp #$0A
    beq run_native_menu_coordinator_before_exceptional_callback_c01e43
    .a8
    cmp #$03
    beq run_native_menu_coordinator_before_exceptional_callback_c01e43
    .a8
    lda #$01
    jsr routine_c029d2
run_native_menu_coordinator_before_exceptional_callback_c01e43:
    .a8
    lda #$80
    tsb a:$A20A
    jsr routine_c02781
    jsr routine_c025ad
    .a8
    lda #$80
    trb a:$A20A
    .a8
    lda #$01
    sta f:$004200
    rep #$20
    lda a:$A21D
    sta f:$000102
    lda a:$A21B
    sta f:$000100
    sep #$20
    .a8
    lda #$01
    sta f:$001D05
    .a8
    lda #$00
    sta f:$7EA162
    sta f:$001D04
    sta f:$001D00
    lda a:$A21F
    sta f:$0019FE
    lda f:$7ECFF6
    beq restore_native_menu_caller_after_normal_exit
