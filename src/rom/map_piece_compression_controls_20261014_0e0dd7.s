.setcpu "65816"
.segment "CODE"
.org $0DD7
map_control_0e0dd7:
    .byte $F1 ; progressive-copy count
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
