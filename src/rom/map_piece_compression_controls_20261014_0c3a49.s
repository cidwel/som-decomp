.setcpu "65816"
.segment "CODE"
.org $3A49
map_control_0c3a49:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
