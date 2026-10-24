; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-gate-header.md.
.setcpu "65816"
.smart
.a8
.i16

read_native_current_program_header_pointer = $C01E
routine_00aebd = $AEBD

.segment "CODE"
.org $AE49
reject_native_pause_gate_for_non_0f_header:
    jsr read_native_current_program_header_pointer
    lda a:$0000,X
    .a8
    cmp #$0F
    bne routine_00aebd
