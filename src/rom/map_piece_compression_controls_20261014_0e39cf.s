.setcpu "65816"
.segment "CODE"
.org $39CF
map_control_0e39cf:
    .byte $E8 ; backreference distance high bits
    .byte $4E ; distance low bit/count
