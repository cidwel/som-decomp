.setcpu "65816"
.segment "CODE"
.org $4A9D
map_control_0d4a9d:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5A ; row-distance/count
