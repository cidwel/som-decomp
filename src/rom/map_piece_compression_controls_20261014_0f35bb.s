.setcpu "65816"
.segment "CODE"
.org $35BB
map_control_0f35bb:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
