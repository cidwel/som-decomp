.setcpu "65816"
.segment "CODE"
.org $1428
map_control_0d1428:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
