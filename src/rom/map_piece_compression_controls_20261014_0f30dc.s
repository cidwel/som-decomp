.setcpu "65816"
.segment "CODE"
.org $30DC
map_control_0f30dc:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
