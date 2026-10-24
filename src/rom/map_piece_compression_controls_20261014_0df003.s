.setcpu "65816"
.segment "CODE"
.org $F003
map_control_0df003:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
