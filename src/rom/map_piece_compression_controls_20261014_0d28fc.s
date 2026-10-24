.setcpu "65816"
.segment "CODE"
.org $28FC
map_control_0d28fc:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
