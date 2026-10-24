.setcpu "65816"
.segment "CODE"
.org $3748
map_control_0f3748:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
