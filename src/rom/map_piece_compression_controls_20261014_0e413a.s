.setcpu "65816"
.segment "CODE"
.org $413A
map_control_0e413a:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
