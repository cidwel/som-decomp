.setcpu "65816"
.segment "CODE"
.org $4828
map_control_0f4828:
    .byte $F2 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
