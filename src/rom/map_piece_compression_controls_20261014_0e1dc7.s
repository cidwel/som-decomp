.setcpu "65816"
.segment "CODE"
.org $1DC7
map_control_0e1dc7:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
