.setcpu "65816"
.segment "CODE"
.org $30AB
map_control_0f30ab:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
