.setcpu "65816"
.segment "CODE"
.org $2722
map_control_0d2722:
    .byte $E8 ; backreference distance high bits
    .byte $9C ; distance low bit/count
