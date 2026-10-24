.setcpu "65816"
.segment "CODE"
.org $4415
map_control_0d4415:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
