.setcpu "65816"
.segment "CODE"
.org $236C
map_control_0f236c:
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
