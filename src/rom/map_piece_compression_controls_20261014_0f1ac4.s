.setcpu "65816"
.segment "CODE"
.org $1AC4
map_control_0f1ac4:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
