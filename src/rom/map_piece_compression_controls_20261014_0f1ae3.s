.setcpu "65816"
.segment "CODE"
.org $1AE3
map_control_0f1ae3:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
