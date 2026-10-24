.setcpu "65816"
.segment "CODE"
.org $67B3
map_control_0c67b3:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
