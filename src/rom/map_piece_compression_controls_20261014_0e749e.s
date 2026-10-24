.setcpu "65816"
.segment "CODE"
.org $749E
map_control_0e749e:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
