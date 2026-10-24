.setcpu "65816"
.segment "CODE"
.org $DB15
map_control_0ddb15:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
