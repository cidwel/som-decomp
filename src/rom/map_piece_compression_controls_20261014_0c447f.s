.setcpu "65816"
.segment "CODE"
.org $447F
map_control_0c447f:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
