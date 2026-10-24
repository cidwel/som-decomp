.setcpu "65816"
.segment "CODE"
.org $1844
map_control_0f1844:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
