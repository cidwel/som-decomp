.setcpu "65816"
.segment "CODE"
.org $F582
map_control_0df582:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
