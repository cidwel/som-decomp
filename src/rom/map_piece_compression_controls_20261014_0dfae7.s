.setcpu "65816"
.segment "CODE"
.org $FAE7
map_control_0dfae7:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
