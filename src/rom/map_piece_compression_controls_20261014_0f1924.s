.setcpu "65816"
.segment "CODE"
.org $1924
map_control_0f1924:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
