.setcpu "65816"
.segment "CODE"
.org $4428
map_control_0f4428:
    .byte $E0 ; previous-row copy escape
    .byte $60 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $6E ; row-distance/count
