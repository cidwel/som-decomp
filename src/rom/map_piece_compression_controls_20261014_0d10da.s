.setcpu "65816"
.segment "CODE"
.org $10DA
map_control_0d10da:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
