.setcpu "65816"
.segment "CODE"
.org $9AEF
map_control_0f9aef:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
