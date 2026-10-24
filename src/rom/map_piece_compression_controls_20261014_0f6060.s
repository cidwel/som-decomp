.setcpu "65816"
.segment "CODE"
.org $6060
map_control_0f6060:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
