.setcpu "65816"
.segment "CODE"
.org $E5BE
map_control_0fe5be:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
