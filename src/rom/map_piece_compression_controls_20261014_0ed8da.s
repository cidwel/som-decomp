.setcpu "65816"
.segment "CODE"
.org $D8DA
map_control_0ed8da:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
