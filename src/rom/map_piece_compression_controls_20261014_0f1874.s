.setcpu "65816"
.segment "CODE"
.org $1874
map_control_0f1874:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
