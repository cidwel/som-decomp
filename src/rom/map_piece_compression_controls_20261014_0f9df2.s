.setcpu "65816"
.segment "CODE"
.org $9DF2
map_control_0f9df2:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
