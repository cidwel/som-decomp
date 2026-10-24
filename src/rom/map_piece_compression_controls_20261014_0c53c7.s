.setcpu "65816"
.segment "CODE"
.org $53C7
map_control_0c53c7:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
