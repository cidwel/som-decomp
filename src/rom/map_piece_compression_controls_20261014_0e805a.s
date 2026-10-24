.setcpu "65816"
.segment "CODE"
.org $805A
map_control_0e805a:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
