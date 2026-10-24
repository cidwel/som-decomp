.setcpu "65816"
.segment "CODE"
.org $B3EB
map_control_0eb3eb:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
