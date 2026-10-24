.setcpu "65816"
.segment "CODE"
.org $8B0C
map_control_0d8b0c:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
