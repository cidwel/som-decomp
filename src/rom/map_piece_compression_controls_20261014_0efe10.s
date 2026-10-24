.setcpu "65816"
.segment "CODE"
.org $FE10
map_control_0efe10:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
