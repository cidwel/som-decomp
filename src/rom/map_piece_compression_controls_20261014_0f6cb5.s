.setcpu "65816"
.segment "CODE"
.org $6CB5
map_control_0f6cb5:
    .byte $F2 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
