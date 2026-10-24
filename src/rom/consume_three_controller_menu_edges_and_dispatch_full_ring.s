; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame.md.
.setcpu "65816"
.smart
.a8
.i16

cycle_controller_to_first_eligible_party_actor = $BCF3
invoke_full_actor_ring_between_native_camera_and_frame_phases = $BEFC
reassign_controller_and_update_hud = $BDC5
routine_02a943 = $2A943

.segment "CODE"
.org $B136
consume_three_controller_menu_edges_and_dispatch_full_ring:
    sep #$30
    lda f:$7ECF00
    bne consume_three_controller_menu_edges_and_dispatch_full_ring_c0b13f
    rts
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b13f:
    lda $D0
    bne consume_three_controller_menu_edges_and_dispatch_full_ring_c0b151
    .a8
    lda #$10
    trb $CC
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b151
    eor $42
    .a8
    eor #$A0
    bne consume_three_controller_menu_edges_and_dispatch_full_ring_c0b151
    inc $2B
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b151:
    lda $E2
    asl
    asl
    ora $E8
    .a8
    and #$04
    ora $F1
    ora $FF
    ora $D0
    ora $52
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b164
    rts
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b164:
    .i8
    ldx #$00
    bit $43
    bpl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b170
    .a8
    lda #$F7
    trb $CC
    bra consume_three_controller_menu_edges_and_dispatch_full_ring_c0b191
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b170:
    lda $D9
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b191
    .a8
    lda #$04
    trb $CC
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b17d
    brl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b207
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b17d:
    .a8
    lda #$40
    trb $CC
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b186
    brl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b215
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b186:
    .a8
    lda #$02
    trb $CC
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b191
    .i8
    ldy #$00
    brl cycle_controller_to_first_eligible_party_actor
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b191:
    .a8
    lda #$01
    trb $CC
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b19a
    brl reassign_controller_and_update_hud
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b19a:
    .i8
    ldx #$01
    bit $45
    bpl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1a6
    .a8
    lda #$F7
    trb $CD
    bra consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1c7
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1a6:
    lda $DA
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1c7
    .a8
    lda #$04
    trb $CD
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1b3
    brl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b207
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1b3:
    .a8
    lda #$40
    trb $CD
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1bc
    brl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b215
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1bc:
    .a8
    lda #$02
    trb $CD
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1c7
    .i8
    ldy #$01
    brl cycle_controller_to_first_eligible_party_actor
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1c7:
    .a8
    lda #$01
    trb $CD
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1d0
    brl reassign_controller_and_update_hud
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1d0:
    .i8
    ldx #$02
    bit $47
    bpl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1dc
    .a8
    lda #$F7
    trb $CE
    bra consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1fd
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1dc:
    lda $DB
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1fd
    .a8
    lda #$04
    trb $CE
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1e9
    brl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b207
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1e9:
    .a8
    lda #$40
    trb $CE
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1f2
    brl consume_three_controller_menu_edges_and_dispatch_full_ring_c0b215
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1f2:
    .a8
    lda #$02
    trb $CE
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1fd
    .i8
    ldy #$02
    brl cycle_controller_to_first_eligible_party_actor
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b1fd:
    .a8
    lda #$01
    trb $CE
    beq consume_three_controller_menu_edges_and_dispatch_full_ring_c0b206
    brl reassign_controller_and_update_hud
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b206:
    rts
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b207:
    lda $D9,X
    .a8
    and #$06
    xba
    .a8
    lda #$00
    rep #$30
    tax
    tay
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b212:
    brl invoke_full_actor_ring_between_native_camera_and_frame_phases
consume_three_controller_menu_edges_and_dispatch_full_ring_c0b215:
    jsl f:routine_02a943
    bcc consume_three_controller_menu_edges_and_dispatch_full_ring_c0b212
    rts
