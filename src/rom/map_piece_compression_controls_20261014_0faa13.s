.setcpu "65816"
.segment "CODE"
.org $AA13
map_control_0faa13:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
