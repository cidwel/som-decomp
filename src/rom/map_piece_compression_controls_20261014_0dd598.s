.setcpu "65816"
.segment "CODE"
.org $D598
map_control_0dd598:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
