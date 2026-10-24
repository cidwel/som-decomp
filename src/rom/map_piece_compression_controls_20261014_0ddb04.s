.setcpu "65816"
.segment "CODE"
.org $DB04
map_control_0ddb04:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
