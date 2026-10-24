.setcpu "65816"
.segment "CODE"
.org $AD83
map_control_0ead83:
    .byte $E5 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
