.setcpu "65816"
.segment "CODE"
.org $C605
map_control_0ec605:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
