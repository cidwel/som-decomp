.setcpu "65816"
.segment "CODE"
.org $3AA3
map_control_0c3aa3:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
