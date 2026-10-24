.setcpu "65816"
.segment "CODE"
.org $72D2
map_control_0d72d2:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
