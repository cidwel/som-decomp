.setcpu "65816"
.segment "CODE"
.org $BCCB
map_control_0ebccb:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
