; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-action-gates.md.
.setcpu "65816"
.smart
.a8
.i16

gate_one_controller_input_and_publish_native_running_velocity = $B6CD

.segment "CODE"
.org $B665
gate_all_three_controller_inputs_and_start_native_running:
    rep #$10
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    lda $D9
    beq gate_all_three_controller_inputs_and_start_native_running_c2b68d
    bmi gate_all_three_controller_inputs_and_start_native_running_c2b68d
    .a8
    and #$06
    xba
    .a8
    lda #$00
    tax
    ldy $42
    sty $01
    lda $CC
    sta $00
    jsr gate_one_controller_input_and_publish_native_running_velocity
    lda $00
    sta $CC
    ldy $01
    sty $42
gate_all_three_controller_inputs_and_start_native_running_c2b68d:
    lda $DA
    beq gate_all_three_controller_inputs_and_start_native_running_c2b6ac
    bmi gate_all_three_controller_inputs_and_start_native_running_c2b6ac
    .a8
    and #$06
    xba
    .a8
    lda #$00
    tax
    ldy $44
    sty $01
    lda $CD
    sta $00
    jsr gate_one_controller_input_and_publish_native_running_velocity
    lda $00
    sta $CD
    ldy $01
    sty $44
gate_all_three_controller_inputs_and_start_native_running_c2b6ac:
    lda $DB
    beq gate_all_three_controller_inputs_and_start_native_running_c2b6cb
    bmi gate_all_three_controller_inputs_and_start_native_running_c2b6cb
    .a8
    and #$06
    xba
    .a8
    lda #$00
    tax
    ldy $46
    sty $01
    lda $CE
    sta $00
    jsr gate_one_controller_input_and_publish_native_running_velocity
    lda $00
    sta $CE
    ldy $01
    sty $46
gate_all_three_controller_inputs_and_start_native_running_c2b6cb:
    plb
    rtl
