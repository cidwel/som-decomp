.setcpu "65816"
.segment "CODE"
.org $7BDF
map_control_0d7bdf:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
