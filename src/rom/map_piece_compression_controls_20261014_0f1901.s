.setcpu "65816"
.segment "CODE"
.org $1901
map_control_0f1901:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
