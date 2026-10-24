.setcpu "65816"
.segment "CODE"
.org $277A
map_control_0f277a:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
