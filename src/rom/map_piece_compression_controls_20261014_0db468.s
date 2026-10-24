.setcpu "65816"
.segment "CODE"
.org $B468
map_control_0db468:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
