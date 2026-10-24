.setcpu "65816"
.segment "CODE"
.org $15D9
map_control_0c15d9:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
