.setcpu "65816"
.segment "CODE"
.org $D8C8
map_control_0ed8c8:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
