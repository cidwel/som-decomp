.setcpu "65816"
.segment "CODE"
.org $2BDD
map_control_0d2bdd:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
