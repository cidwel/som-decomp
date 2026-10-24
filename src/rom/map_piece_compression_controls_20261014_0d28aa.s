.setcpu "65816"
.segment "CODE"
.org $28AA
map_control_0d28aa:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
