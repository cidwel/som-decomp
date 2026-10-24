.setcpu "65816"
.segment "CODE"
.org $7AF7
map_control_0c7af7:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
