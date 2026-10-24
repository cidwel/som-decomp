.setcpu "65816"
.segment "CODE"
.org $8852
map_control_0c8852:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
