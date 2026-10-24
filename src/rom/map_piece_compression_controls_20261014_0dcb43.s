.setcpu "65816"
.segment "CODE"
.org $CB43
map_control_0dcb43:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
