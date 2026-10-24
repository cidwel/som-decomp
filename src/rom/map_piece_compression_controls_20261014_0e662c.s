.setcpu "65816"
.segment "CODE"
.org $662C
map_control_0e662c:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
