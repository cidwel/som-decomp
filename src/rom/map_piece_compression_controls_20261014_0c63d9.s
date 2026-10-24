.setcpu "65816"
.segment "CODE"
.org $63D9
map_control_0c63d9:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
