.setcpu "65816"
.segment "CODE"
.org $EEB3
map_control_0deeb3:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
