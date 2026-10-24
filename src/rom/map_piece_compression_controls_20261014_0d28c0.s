.setcpu "65816"
.segment "CODE"
.org $28C0
map_control_0d28c0:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
