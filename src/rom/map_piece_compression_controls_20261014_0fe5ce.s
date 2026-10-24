.setcpu "65816"
.segment "CODE"
.org $E5CE
map_control_0fe5ce:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
