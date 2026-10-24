.setcpu "65816"
.segment "CODE"
.org $7877
map_control_0e7877:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
