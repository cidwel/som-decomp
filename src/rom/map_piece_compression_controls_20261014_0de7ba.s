.setcpu "65816"
.segment "CODE"
.org $E7BA
map_control_0de7ba:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
