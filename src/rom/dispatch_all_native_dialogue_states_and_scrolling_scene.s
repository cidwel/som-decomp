; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-coordinator.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_seven_scrolling_dialogue_states = $CC0900

.segment "CODE"
.org $0165
dispatch_all_native_dialogue_states_and_scrolling_scene:
    phb
    phd
    .i16
    ldx #$0000
    phx
    pld
    .a8
    lda #$00
    pha
    plb
    lda $29
    .a8
    and #$07
    sta a:$1D05
    .a8
    cmp #$07
    bne dispatch_all_native_dialogue_states_and_scrolling_scene_c00181
    .a8
    lda #$01
    sta f:$7EA162
dispatch_all_native_dialogue_states_and_scrolling_scene_c00181:
    .a8
    lda #$00
    xba
    lda a:$1D04
    .a8
    and #$02
    beq dispatch_all_native_dialogue_states_and_scrolling_scene_c0018e
    brl dispatch_all_native_dialogue_states_and_scrolling_scene_c0021f
dispatch_all_native_dialogue_states_and_scrolling_scene_c0018e:
    .a8
    lda #$01
    tsb a:$1D04
    lda a:$1D03
    ldy a:$1D01
    pha
    plb
    lda f:$7EA170
    .a8
    cmp #$7D
    bne dispatch_all_native_dialogue_states_and_scrolling_scene_c001a9
    jsl f:dispatch_seven_scrolling_dialogue_states
    bra dispatch_all_native_dialogue_states_and_scrolling_scene_c0021f
dispatch_all_native_dialogue_states_and_scrolling_scene_c001a9:
    .a8
    cmp #$00
    bne dispatch_all_native_dialogue_states_and_scrolling_scene_c001c4
    lda a:$0000,Y
    .a8
    cmp #$7D
    bne dispatch_all_native_dialogue_states_and_scrolling_scene_c001ba
    jsl f:dispatch_seven_scrolling_dialogue_states
    bra dispatch_all_native_dialogue_states_and_scrolling_scene_c0021f
dispatch_all_native_dialogue_states_and_scrolling_scene_c001ba:
    .a8
    cmp #$50
    bcc dispatch_all_native_dialogue_states_and_scrolling_scene_c001d7
    .a8
    cmp #$60
    bcc dispatch_all_native_dialogue_states_and_scrolling_scene_c001c4
    .a8
    lda #$53
dispatch_all_native_dialogue_states_and_scrolling_scene_c001c4:
    pha
    sec
    .a8
    sbc #$50
    asl
    tax
    .a8
    lda #$7E
    pha
    plb
    pla
    sta a:$A170
    jsr ($10DA,X)
    bra dispatch_all_native_dialogue_states_and_scrolling_scene_c0021f
dispatch_all_native_dialogue_states_and_scrolling_scene_c001d7:
    .a8
    lda #$00
    pha
    plb
    lda a:$1D04
    .a8
    and #$80
    beq dispatch_all_native_dialogue_states_and_scrolling_scene_c001ed
    rep #$20
    lda f:$7EA1D5
    sta a:$1D01
    sep #$20
dispatch_all_native_dialogue_states_and_scrolling_scene_c001ed:
    .a8
    lda #$00
    sta f:$7EA15D
    .a8
    lda #$01
    trb a:$1D04
    .a8
    lda #$04
    trb a:$1D00
    .a8
    lda #$80
    bit a:$1D00
    beq dispatch_all_native_dialogue_states_and_scrolling_scene_c0021f
    trb a:$1D00
    trb a:$1D04
    lda f:$7EA187
    .a8
    bit #$01
    bne dispatch_all_native_dialogue_states_and_scrolling_scene_c0021f
    .a8
    lda #$20
    trb a:$1D04
    trb a:$1D12
    .a8
    lda #$01
    trb a:$1D10
dispatch_all_native_dialogue_states_and_scrolling_scene_c0021f:
    .a8
    lda #$00
    sta f:$001D13
    pld
    plb
    plp
    rtl
