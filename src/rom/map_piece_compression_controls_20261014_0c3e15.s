.setcpu "65816"
.segment "CODE"
.org $3E15
map_control_0c3e15:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
