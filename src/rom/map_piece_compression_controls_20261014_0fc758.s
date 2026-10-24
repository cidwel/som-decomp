.setcpu "65816"
.segment "CODE"
.org $C758
map_control_0fc758:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
