.setcpu "65816"
.segment "CODE"
.org $3C45
map_control_0d3c45:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
