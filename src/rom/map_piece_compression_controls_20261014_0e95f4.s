.setcpu "65816"
.segment "CODE"
.org $95F4
map_control_0e95f4:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
