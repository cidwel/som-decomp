.setcpu "65816"
.segment "CODE"
.org $2141
map_control_0c2141:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
