.setcpu "65816"
.segment "CODE"
.org $CE3B
map_control_0dce3b:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
