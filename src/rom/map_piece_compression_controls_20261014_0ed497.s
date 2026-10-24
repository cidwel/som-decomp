.setcpu "65816"
.segment "CODE"
.org $D497
map_control_0ed497:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
