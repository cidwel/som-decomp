.setcpu "65816"
.segment "CODE"
.org $9865
map_control_0e9865:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
