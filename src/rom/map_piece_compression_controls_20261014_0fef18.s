.setcpu "65816"
.segment "CODE"
.org $EF18
map_control_0fef18:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
