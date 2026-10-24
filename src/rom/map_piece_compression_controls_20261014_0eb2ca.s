.setcpu "65816"
.segment "CODE"
.org $B2CA
map_control_0eb2ca:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
