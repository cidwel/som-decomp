.setcpu "65816"
.segment "CODE"
.org $0377
map_control_0f0377:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E2 ; previous-row copy count
