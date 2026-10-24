.setcpu "65816"
.segment "CODE"
.org $E36E
map_control_0fe36e:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
