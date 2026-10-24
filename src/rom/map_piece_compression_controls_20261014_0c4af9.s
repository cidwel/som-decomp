.setcpu "65816"
.segment "CODE"
.org $4AF9
map_control_0c4af9:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
