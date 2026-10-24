.setcpu "65816"
.segment "CODE"
.org $166E
map_control_0e166e:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
