.setcpu "65816"
.segment "CODE"
.org $25E7
map_control_0c25e7:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
