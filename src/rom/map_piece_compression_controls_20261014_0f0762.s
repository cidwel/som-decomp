.setcpu "65816"
.segment "CODE"
.org $0762
map_control_0f0762:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
