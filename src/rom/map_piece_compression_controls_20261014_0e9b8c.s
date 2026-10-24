.setcpu "65816"
.segment "CODE"
.org $9B8C
map_control_0e9b8c:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
