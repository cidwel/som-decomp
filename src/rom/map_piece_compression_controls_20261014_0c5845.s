.setcpu "65816"
.segment "CODE"
.org $5845
map_control_0c5845:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
