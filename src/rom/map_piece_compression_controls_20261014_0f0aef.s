.setcpu "65816"
.segment "CODE"
.org $0AEF
map_control_0f0aef:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
