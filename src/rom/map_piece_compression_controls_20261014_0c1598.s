.setcpu "65816"
.segment "CODE"
.org $1598
map_control_0c1598:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
