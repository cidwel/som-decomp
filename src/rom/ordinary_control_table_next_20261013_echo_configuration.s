; Typed DSP configuration records; no sequence, BRR or audio payload.
.setcpu "65816"
.segment "RODATA"
.org $0708
ordinary_control_table_next_20261013_echo_configuration:
    .byte $02, $1E, $00, $00 ; row 00: delay, echo volume, feedback, FIR selector
    .byte $02, $1E, $00, $00 ; row 01: delay, echo volume, feedback, FIR selector
    .byte $06, $40, $00, $00 ; row 02: delay, echo volume, feedback, FIR selector
    .byte $06, $40, $25, $00 ; row 03: delay, echo volume, feedback, FIR selector
    .byte $04, $40, $1E, $00 ; row 04: delay, echo volume, feedback, FIR selector
    .byte $02, $B4, $3F, $00 ; row 05: delay, echo volume, feedback, FIR selector
    .byte $02, $D0, $1E, $01 ; row 06: delay, echo volume, feedback, FIR selector
    .byte $08, $48, $30, $00 ; row 07: delay, echo volume, feedback, FIR selector
    .byte $08, $3A, $58, $00 ; row 08: delay, echo volume, feedback, FIR selector
    .byte $03, $8F, $00, $01 ; row 09: delay, echo volume, feedback, FIR selector
    .byte $03, $40, $00, $00 ; row 0A: delay, echo volume, feedback, FIR selector
    .byte $0B, $20, $65, $00 ; row 0B: delay, echo volume, feedback, FIR selector
    .byte $0B, $40, $5C, $00 ; row 0C: delay, echo volume, feedback, FIR selector
    .byte $06, $40, $60, $01 ; row 0D: delay, echo volume, feedback, FIR selector
    .byte $00, $54, $3C, $00 ; row 0E: delay, echo volume, feedback, FIR selector
    .byte $06, $20, $68, $00 ; row 0F: delay, echo volume, feedback, FIR selector
