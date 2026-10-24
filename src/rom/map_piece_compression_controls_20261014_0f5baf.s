.setcpu "65816"
.segment "CODE"
.org $5BAF
map_control_0f5baf:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
