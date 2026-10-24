.setcpu "65816"
.segment "CODE"
.org $95CE
map_control_0e95ce:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
