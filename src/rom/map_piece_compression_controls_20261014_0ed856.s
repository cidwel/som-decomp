.setcpu "65816"
.segment "CODE"
.org $D856
map_control_0ed856:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
