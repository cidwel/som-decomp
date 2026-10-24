.setcpu "65816"
.segment "CODE"
.org $E979
map_control_0ee979:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
