.setcpu "65816"
.segment "CODE"
.org $E8F9
map_control_0fe8f9:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
