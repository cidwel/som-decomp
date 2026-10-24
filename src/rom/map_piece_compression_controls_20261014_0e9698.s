.setcpu "65816"
.segment "CODE"
.org $9698
map_control_0e9698:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
