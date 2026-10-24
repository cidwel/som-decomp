.setcpu "65816"
.segment "CODE"
.org $36FD
map_control_0d36fd:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
