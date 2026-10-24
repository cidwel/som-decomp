.setcpu "65816"
.segment "CODE"
.org $702A
map_control_0f702a:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
