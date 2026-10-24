.setcpu "65816"
.segment "CODE"
.org $FFFA
map_control_0efffa:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
