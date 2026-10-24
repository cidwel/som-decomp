.setcpu "65816"
.segment "CODE"
.org $3C04
map_control_0f3c04:
    .byte $E0 ; previous-row copy escape
    .byte $5F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
