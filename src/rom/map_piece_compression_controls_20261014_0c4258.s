.setcpu "65816"
.segment "CODE"
.org $4258
map_control_0c4258:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
