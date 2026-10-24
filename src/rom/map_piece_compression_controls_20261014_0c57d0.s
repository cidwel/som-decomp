.setcpu "65816"
.segment "CODE"
.org $57D0
map_control_0c57d0:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
