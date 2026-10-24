.setcpu "65816"
.segment "CODE"
.org $F483
map_control_0cf483:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E1 ; previous-row copy count
