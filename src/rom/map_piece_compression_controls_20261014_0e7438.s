.setcpu "65816"
.segment "CODE"
.org $7438
map_control_0e7438:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
