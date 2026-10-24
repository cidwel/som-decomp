.setcpu "65816"
.segment "CODE"
.org $F5BA
map_control_0cf5ba:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
