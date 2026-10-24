.setcpu "65816"
.segment "CODE"
.org $3F37
map_control_0c3f37:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
