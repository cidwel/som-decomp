.setcpu "65816"
.segment "CODE"
.org $DF2B
map_control_0fdf2b:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
