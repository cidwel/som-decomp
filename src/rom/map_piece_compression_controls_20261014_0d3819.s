.setcpu "65816"
.segment "CODE"
.org $3819
map_control_0d3819:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
