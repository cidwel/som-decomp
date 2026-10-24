.setcpu "65816"
.segment "CODE"
.org $72BC
map_control_0d72bc:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
