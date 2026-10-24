.setcpu "65816"
.segment "CODE"
.org $AD8F
map_control_0fad8f:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
