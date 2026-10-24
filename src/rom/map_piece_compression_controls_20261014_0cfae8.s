.setcpu "65816"
.segment "CODE"
.org $FAE8
map_control_0cfae8:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
