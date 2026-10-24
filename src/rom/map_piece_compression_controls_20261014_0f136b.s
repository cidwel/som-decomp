.setcpu "65816"
.segment "CODE"
.org $136B
map_control_0f136b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
