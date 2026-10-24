.setcpu "65816"
.segment "CODE"
.org $801C
map_control_0f801c:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
