.setcpu "65816"
.segment "CODE"
.org $C679
map_control_0fc679:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
