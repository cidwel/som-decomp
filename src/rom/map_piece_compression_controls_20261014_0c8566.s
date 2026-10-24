.setcpu "65816"
.segment "CODE"
.org $8566
map_control_0c8566:
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
