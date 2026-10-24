.setcpu "65816"
.segment "CODE"
.org $F9CE
map_control_0ff9ce:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
