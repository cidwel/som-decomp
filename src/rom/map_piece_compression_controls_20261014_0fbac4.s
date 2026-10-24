.setcpu "65816"
.segment "CODE"
.org $BAC4
map_control_0fbac4:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
