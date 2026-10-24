.setcpu "65816"
.segment "CODE"
.org $ACB8
map_control_0dacb8:
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
