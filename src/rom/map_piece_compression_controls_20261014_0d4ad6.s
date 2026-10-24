.setcpu "65816"
.segment "CODE"
.org $4AD6
map_control_0d4ad6:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
