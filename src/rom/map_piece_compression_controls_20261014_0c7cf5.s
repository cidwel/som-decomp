.setcpu "65816"
.segment "CODE"
.org $7CF5
map_control_0c7cf5:
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
