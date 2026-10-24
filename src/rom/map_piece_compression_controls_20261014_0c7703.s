.setcpu "65816"
.segment "CODE"
.org $7703
map_control_0c7703:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
