.setcpu "65816"
.segment "CODE"
.org $1814
map_control_0d1814:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
