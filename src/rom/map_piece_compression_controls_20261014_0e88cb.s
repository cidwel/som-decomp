.setcpu "65816"
.segment "CODE"
.org $88CB
map_control_0e88cb:
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
