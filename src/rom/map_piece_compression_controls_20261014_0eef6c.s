.setcpu "65816"
.segment "CODE"
.org $EF6C
map_control_0eef6c:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $71 ; distance low bit/count
