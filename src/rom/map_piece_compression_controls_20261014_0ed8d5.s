.setcpu "65816"
.segment "CODE"
.org $D8D5
map_control_0ed8d5:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
