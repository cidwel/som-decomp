.setcpu "65816"
.segment "CODE"
.org $F857
map_control_0cf857:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
