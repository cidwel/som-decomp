.setcpu "65816"
.segment "CODE"
.org $1806
map_control_0f1806:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
