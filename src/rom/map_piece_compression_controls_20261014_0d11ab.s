.setcpu "65816"
.segment "CODE"
.org $11AB
map_control_0d11ab:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
