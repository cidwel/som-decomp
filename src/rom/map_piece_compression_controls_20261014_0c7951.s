.setcpu "65816"
.segment "CODE"
.org $7951
map_control_0c7951:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
