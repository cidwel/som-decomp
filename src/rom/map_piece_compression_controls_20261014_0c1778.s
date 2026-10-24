.setcpu "65816"
.segment "CODE"
.org $1778
map_control_0c1778:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
