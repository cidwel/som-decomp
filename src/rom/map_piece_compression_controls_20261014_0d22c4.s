.setcpu "65816"
.segment "CODE"
.org $22C4
map_control_0d22c4:
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
