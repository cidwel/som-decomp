.setcpu "65816"
.segment "CODE"
.org $ACBE
map_control_0eacbe:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
