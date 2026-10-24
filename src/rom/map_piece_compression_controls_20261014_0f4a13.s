.setcpu "65816"
.segment "CODE"
.org $4A13
map_control_0f4a13:
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
