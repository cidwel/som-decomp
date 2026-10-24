.setcpu "65816"
.segment "CODE"
.org $C3AA
map_control_0dc3aa:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
