.setcpu "65816"
.segment "CODE"
.org $AEC5
map_control_0faec5:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
