.setcpu "65816"
.segment "CODE"
.org $51B8
map_control_0f51b8:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
