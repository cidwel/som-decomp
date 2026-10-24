.setcpu "65816"
.segment "CODE"
.org $CF49
map_control_0ecf49:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
