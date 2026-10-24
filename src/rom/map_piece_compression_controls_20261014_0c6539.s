.setcpu "65816"
.segment "CODE"
.org $6539
map_control_0c6539:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
