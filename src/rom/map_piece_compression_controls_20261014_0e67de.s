.setcpu "65816"
.segment "CODE"
.org $67DE
map_control_0e67de:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
