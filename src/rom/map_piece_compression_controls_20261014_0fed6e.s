.setcpu "65816"
.segment "CODE"
.org $ED6E
map_control_0fed6e:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
