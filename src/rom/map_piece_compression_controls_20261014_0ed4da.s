.setcpu "65816"
.segment "CODE"
.org $D4DA
map_control_0ed4da:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
