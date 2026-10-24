.setcpu "65816"
.segment "CODE"
.org $47E3
map_control_0f47e3:
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
