.setcpu "65816"
.segment "CODE"
.org $7362
map_control_0d7362:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
