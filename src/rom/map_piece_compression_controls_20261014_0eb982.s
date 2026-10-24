.setcpu "65816"
.segment "CODE"
.org $B982
map_control_0eb982:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
