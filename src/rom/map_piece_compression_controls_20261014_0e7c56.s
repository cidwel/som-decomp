.setcpu "65816"
.segment "CODE"
.org $7C56
map_control_0e7c56:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
