.setcpu "65816"
.segment "CODE"
.org $5862
map_control_0c5862:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
