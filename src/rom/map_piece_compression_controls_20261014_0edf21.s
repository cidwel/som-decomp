.setcpu "65816"
.segment "CODE"
.org $DF21
map_control_0edf21:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E4 ; previous-row copy count
