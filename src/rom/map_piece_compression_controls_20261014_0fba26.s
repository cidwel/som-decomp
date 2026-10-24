.setcpu "65816"
.segment "CODE"
.org $BA26
map_control_0fba26:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
