.setcpu "65816"
.segment "CODE"
.org $21E4
map_control_0c21e4:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
