.setcpu "65816"
.segment "CODE"
.org $45EA
map_control_0d45ea:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
