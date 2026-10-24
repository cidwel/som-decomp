.setcpu "65816"
.segment "CODE"
.org $B953
map_control_0eb953:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
