.setcpu "65816"
.segment "CODE"
.org $1311
map_control_0d1311:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
