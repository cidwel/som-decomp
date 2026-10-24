.setcpu "65816"
.segment "CODE"
.org $8144
map_control_0d8144:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
