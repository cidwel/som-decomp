.setcpu "65816"
.segment "CODE"
.org $48AD
map_control_0d48ad:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
