.setcpu "65816"
.segment "CODE"
.org $6526
map_control_0f6526:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
