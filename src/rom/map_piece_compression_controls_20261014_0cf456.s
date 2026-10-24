.setcpu "65816"
.segment "CODE"
.org $F456
map_control_0cf456:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $F1 ; progressive-copy count
