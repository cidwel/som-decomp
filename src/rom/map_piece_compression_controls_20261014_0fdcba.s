.setcpu "65816"
.segment "CODE"
.org $DCBA
map_control_0fdcba:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
