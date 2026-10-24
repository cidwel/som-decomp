.setcpu "65816"
.segment "CODE"
.org $61DF
map_control_0e61df:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
