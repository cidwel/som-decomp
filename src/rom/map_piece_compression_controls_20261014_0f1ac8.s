.setcpu "65816"
.segment "CODE"
.org $1AC8
map_control_0f1ac8:
    .byte $E0 ; previous-row copy escape
    .byte $DE ; row-distance/count
