.setcpu "65816"
.segment "CODE"
.org $E0BE
map_control_0de0be:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
