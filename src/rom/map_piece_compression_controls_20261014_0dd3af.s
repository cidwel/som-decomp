.setcpu "65816"
.segment "CODE"
.org $D3AF
map_control_0dd3af:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
