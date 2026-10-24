.setcpu "65816"
.segment "CODE"
.org $C616
map_control_0dc616:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
