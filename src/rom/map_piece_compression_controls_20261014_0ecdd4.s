.setcpu "65816"
.segment "CODE"
.org $CDD4
map_control_0ecdd4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
