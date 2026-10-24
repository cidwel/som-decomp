.setcpu "65816"
.segment "CODE"
.org $819E
map_control_0c819e:
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count
