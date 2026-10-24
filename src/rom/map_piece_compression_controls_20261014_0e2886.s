.setcpu "65816"
.segment "CODE"
.org $2886
map_control_0e2886:
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
