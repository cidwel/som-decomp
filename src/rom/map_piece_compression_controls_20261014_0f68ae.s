.setcpu "65816"
.segment "CODE"
.org $68AE
map_control_0f68ae:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
