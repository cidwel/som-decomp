.setcpu "65816"
.segment "CODE"
.org $61FF
map_control_0d61ff:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
