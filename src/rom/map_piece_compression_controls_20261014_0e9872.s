.setcpu "65816"
.segment "CODE"
.org $9872
map_control_0e9872:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
