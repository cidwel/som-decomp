.setcpu "65816"
.segment "CODE"
.org $6764
map_control_0e6764:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
