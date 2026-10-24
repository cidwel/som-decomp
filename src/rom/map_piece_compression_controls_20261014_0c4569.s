.setcpu "65816"
.segment "CODE"
.org $4569
map_control_0c4569:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
