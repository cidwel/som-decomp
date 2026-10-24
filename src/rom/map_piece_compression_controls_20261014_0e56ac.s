.setcpu "65816"
.segment "CODE"
.org $56AC
map_control_0e56ac:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
