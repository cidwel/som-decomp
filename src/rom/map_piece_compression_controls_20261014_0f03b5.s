.setcpu "65816"
.segment "CODE"
.org $03B5
map_control_0f03b5:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
