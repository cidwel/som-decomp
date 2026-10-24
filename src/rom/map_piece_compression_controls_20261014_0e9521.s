.setcpu "65816"
.segment "CODE"
.org $9521
map_control_0e9521:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
