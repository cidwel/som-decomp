.setcpu "65816"
.segment "CODE"
.org $62EA
map_control_0f62ea:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
