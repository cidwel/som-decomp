.setcpu "65816"
.segment "CODE"
.org $72E8
map_control_0d72e8:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
