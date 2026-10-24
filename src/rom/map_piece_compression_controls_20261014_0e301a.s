.setcpu "65816"
.segment "CODE"
.org $301A
map_control_0e301a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
