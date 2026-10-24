.setcpu "65816"
.segment "CODE"
.org $E373
map_control_0de373:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
