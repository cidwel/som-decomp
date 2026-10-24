.setcpu "65816"
.segment "CODE"
.org $E4E6
map_control_0ee4e6:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $F3 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
