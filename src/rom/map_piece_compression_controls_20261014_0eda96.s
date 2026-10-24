.setcpu "65816"
.segment "CODE"
.org $DA96
map_control_0eda96:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
