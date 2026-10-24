.setcpu "65816"
.segment "CODE"
.org $B967
map_control_0eb967:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
