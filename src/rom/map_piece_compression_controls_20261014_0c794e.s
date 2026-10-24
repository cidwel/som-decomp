.setcpu "65816"
.segment "CODE"
.org $794E
map_control_0c794e:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
