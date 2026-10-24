.setcpu "65816"
.segment "CODE"
.org $53CE
map_control_0d53ce:
    .byte $E8 ; backreference distance high bits
    .byte $73 ; distance low bit/count
