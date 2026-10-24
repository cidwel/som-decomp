.setcpu "65816"
.segment "CODE"
.org $2BC5
map_control_0c2bc5:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
