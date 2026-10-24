.setcpu "65816"
.segment "CODE"
.org $2549
map_control_0e2549:
    .byte $F3 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $F3 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
