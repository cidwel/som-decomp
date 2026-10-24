.setcpu "65816"
.segment "CODE"
.org $FABF
map_control_0dfabf:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
