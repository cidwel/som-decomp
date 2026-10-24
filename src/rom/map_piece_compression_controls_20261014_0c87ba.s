.setcpu "65816"
.segment "CODE"
.org $87BA
map_control_0c87ba:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
