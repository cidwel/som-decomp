.setcpu "65816"
.segment "CODE"
.org $D88C
map_control_0ed88c:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
