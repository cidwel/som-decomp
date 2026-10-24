.setcpu "65816"
.segment "CODE"
.org $AAD7
map_control_0eaad7:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
