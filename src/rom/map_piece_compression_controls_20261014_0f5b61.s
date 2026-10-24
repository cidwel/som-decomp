.setcpu "65816"
.segment "CODE"
.org $5B61
map_control_0f5b61:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
