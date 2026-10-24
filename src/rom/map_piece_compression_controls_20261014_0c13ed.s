.setcpu "65816"
.segment "CODE"
.org $13ED
map_control_0c13ed:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
