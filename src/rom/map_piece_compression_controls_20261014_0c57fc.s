.setcpu "65816"
.segment "CODE"
.org $57FC
map_control_0c57fc:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
