.setcpu "65816"
.segment "CODE"
.org $72F3
map_control_0d72f3:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
