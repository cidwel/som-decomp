.setcpu "65816"
.segment "CODE"
.org $AE86
map_control_0eae86:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
