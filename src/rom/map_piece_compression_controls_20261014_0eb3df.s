.setcpu "65816"
.segment "CODE"
.org $B3DF
map_control_0eb3df:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
