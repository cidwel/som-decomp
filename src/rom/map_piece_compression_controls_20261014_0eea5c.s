.setcpu "65816"
.segment "CODE"
.org $EA5C
map_control_0eea5c:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
