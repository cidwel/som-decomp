.setcpu "65816"
.segment "CODE"
.org $1445
map_control_0d1445:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
