.setcpu "65816"
.segment "CODE"
.org $1881
map_control_0f1881:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
