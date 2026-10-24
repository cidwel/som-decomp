.setcpu "65816"
.segment "CODE"
.org $984B
map_control_0e984b:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
