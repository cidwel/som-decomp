.setcpu "65816"
.segment "CODE"
.org $1DDA
map_control_0e1dda:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
