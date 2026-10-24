.setcpu "65816"
.segment "CODE"
.org $752A
map_control_0d752a:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
