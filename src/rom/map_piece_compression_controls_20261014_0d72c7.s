.setcpu "65816"
.segment "CODE"
.org $72C7
map_control_0d72c7:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
