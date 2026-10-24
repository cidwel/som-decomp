.setcpu "65816"
.segment "CODE"
.org $BFAD
map_control_0ebfad:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
