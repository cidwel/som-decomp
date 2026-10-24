.setcpu "65816"
.segment "CODE"
.org $2921
map_control_0e2921:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
