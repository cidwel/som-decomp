.setcpu "65816"
.segment "CODE"
.org $547F
map_control_0f547f:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
