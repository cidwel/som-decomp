.setcpu "65816"
.segment "CODE"
.org $64C2
map_control_0c64c2:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
