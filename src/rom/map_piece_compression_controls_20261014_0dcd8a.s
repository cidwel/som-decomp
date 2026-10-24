.setcpu "65816"
.segment "CODE"
.org $CD8A
map_control_0dcd8a:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
