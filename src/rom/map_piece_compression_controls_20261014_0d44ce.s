.setcpu "65816"
.segment "CODE"
.org $44CE
map_control_0d44ce:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
