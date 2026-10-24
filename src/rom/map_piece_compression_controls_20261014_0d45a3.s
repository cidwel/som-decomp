.setcpu "65816"
.segment "CODE"
.org $45A3
map_control_0d45a3:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
