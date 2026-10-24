.setcpu "65816"
.segment "CODE"
.org $1980
map_control_0f1980:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
