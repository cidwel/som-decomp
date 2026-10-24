.setcpu "65816"
.segment "CODE"
.org $2963
map_control_0e2963:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
