.setcpu "65816"
.segment "CODE"
.org $72DD
map_control_0d72dd:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
