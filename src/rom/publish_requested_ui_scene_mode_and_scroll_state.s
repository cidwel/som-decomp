; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-interrupts.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $890B
publish_requested_ui_scene_mode_and_scroll_state:
    sep #$20
    .a8
    lda #$13
    sta a:$212C
    .a8
    lda #$80
    trb $60
    bne publish_requested_ui_scene_mode_and_scroll_state_c08919
    rts
publish_requested_ui_scene_mode_and_scroll_state_c08919:
    sep #$20
    .a8
    lda #$03
    bit $F2
    beq publish_requested_ui_scene_mode_and_scroll_state_c08928
    lda $51
    sta a:$2100
    bra publish_requested_ui_scene_mode_and_scroll_state_c08935
publish_requested_ui_scene_mode_and_scroll_state_c08928:
    lda $FE
    beq publish_requested_ui_scene_mode_and_scroll_state_c08935
    lsr
    lsr
    .a8
    and #$0F
    .a8
    eor #$0F
    sta a:$2100
publish_requested_ui_scene_mode_and_scroll_state_c08935:
    stz a:$211A
    bit $F2
    bpl publish_requested_ui_scene_mode_and_scroll_state_c08990
    lda $2C
    .a8
    and #$C0
    sta a:$420C
    lda $36
    sta a:$211B
    lda $37
    sta a:$211B
    lda $36
    sta a:$211E
    lda $37
    sta a:$211E
    lda $38
    sta a:$211C
    lda $39
    sta a:$211C
    lda $38
    .a8
    eor #$FF
    clc
    .a8
    adc #$01
    sta a:$211D
    lda $39
    .a8
    eor #$FF
    .a8
    adc #$00
    sta a:$211D
    lda $3E
    sta a:$210D
    lda $3F
    sta a:$210D
    lda $40
    sta a:$210E
    lda $41
    sta a:$210E
    .a8
    lda #$07
    sta a:$2105
    jmp publish_requested_ui_scene_mode_and_scroll_state_c08a2e
publish_requested_ui_scene_mode_and_scroll_state_c08990:
    lda $60
    lsr
    lsr
    .a8
    ora #$0C
    sta a:$0FE0
    sta a:$0FEA
    sta a:$0FEA
    sta a:$0FFE
    .a8
    and #$C0
    lda $60
    .a8
    ora #$10
    sta a:$0FDA
    sta a:$0FDD
    inc
    sta a:$0FE4
    sta a:$0FE7
    inc
    sta a:$0FEE
    sta a:$0FF1
    inc
    sta a:$0FF8
    sta a:$0FFB
    lda $F8
    lsr
    lsr
    lsr
    sta $50
    .a8
    eor #$1F
    clc
    .a8
    adc #$4C
    sta a:$0FD8
    sta a:$0FE2
    sta a:$0FEC
    sta a:$0FF6
    inc
    sta a:$4209
    lda a:$0FD8
    .a8
    and #$7F
    sta a:$0F00
    lda $2C
    .a8
    ora #$3F
    sta a:$420C
    .a8
    lda #$01
    sta a:$2105
    rep #$20
    lda $A9
    tax
    stx a:$210D
    xba
    tax
    stx a:$210D
    lda $AD
    sep #$20
    sta a:$210F
    xba
    sta a:$210F
    lda $50
    .a8
    eor #$1F
    sta a:$1300
    sta a:$1700
    .a8
    lda #$00
    sta a:$1301
    sta a:$1701
    lda $50
    lsr
    clc
    adc $50
    dec
    sta $50
    sta a:$2110
    .a8
    lda #$00
    sta a:$2110
publish_requested_ui_scene_mode_and_scroll_state_c08a2e:
    lda $FA
    sta a:$211F
    lda $FB
    .a8
    and #$03
    sta a:$211F
    lda $FC
    sta a:$2120
    lda $FD
    .a8
    and #$03
    sta a:$2120
    .a8
    lda #$01
    trb $EC
    rts
