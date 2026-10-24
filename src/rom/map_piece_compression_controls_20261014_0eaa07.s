.setcpu "65816"
.segment "CODE"
.org $AA07
map_control_0eaa07:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
