.setcpu "65816"
.segment "CODE"
.org $E4A9
map_control_0de4a9:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
