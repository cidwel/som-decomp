.setcpu "65816"
.segment "CODE"
.org $90FE
map_control_0c90fe:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
