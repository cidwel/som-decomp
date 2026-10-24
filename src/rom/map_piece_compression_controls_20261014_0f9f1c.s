.setcpu "65816"
.segment "CODE"
.org $9F1C
map_control_0f9f1c:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
