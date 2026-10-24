.setcpu "65816"
.segment "CODE"
.org $4859
map_control_0f4859:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
