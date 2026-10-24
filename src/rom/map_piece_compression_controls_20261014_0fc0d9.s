.setcpu "65816"
.segment "CODE"
.org $C0D9
map_control_0fc0d9:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
