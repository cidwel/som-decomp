.setcpu "65816"
.segment "CODE"
.org $B62A
map_control_0eb62a:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
