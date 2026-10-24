.setcpu "65816"
.segment "CODE"
.org $520C
map_control_0e520c:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
