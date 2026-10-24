.setcpu "65816"
.segment "CODE"
.org $9188
map_control_0c9188:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
