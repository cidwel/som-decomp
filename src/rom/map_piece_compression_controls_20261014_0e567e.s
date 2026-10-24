.setcpu "65816"
.segment "CODE"
.org $567E
map_control_0e567e:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
