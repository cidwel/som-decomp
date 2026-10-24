.setcpu "65816"
.segment "CODE"
.org $3BC4
map_control_0c3bc4:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
