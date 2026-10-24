.setcpu "65816"
.segment "CODE"
.org $C452
map_control_0fc452:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
