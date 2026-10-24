.setcpu "65816"
.segment "CODE"
.org $28C4
map_control_0d28c4:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
