.setcpu "65816"
.segment "CODE"
.org $44E5
map_control_0d44e5:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
