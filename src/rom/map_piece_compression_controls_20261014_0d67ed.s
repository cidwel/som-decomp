.setcpu "65816"
.segment "CODE"
.org $67ED
map_control_0d67ed:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $F3 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E4 ; previous-row copy count
