.setcpu "65816"
.segment "CODE"
.org $1B27
map_control_0f1b27:
    .byte $E0 ; previous-row copy escape
    .byte $BA ; row-distance/count
