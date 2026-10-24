.setcpu "65816"
.segment "CODE"
.org $7CD9
map_control_0c7cd9:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
