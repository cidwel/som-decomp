.setcpu "65816"
.segment "CODE"
.org $514F
map_control_0f514f:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
