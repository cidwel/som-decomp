.setcpu "65816"
.segment "CODE"
.org $46C2
map_control_0d46c2:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
