.setcpu "65816"
.segment "CODE"
.org $870F
map_control_0c870f:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
