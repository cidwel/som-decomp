.setcpu "65816"
.segment "CODE"
.org $2957
map_control_0d2957:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
