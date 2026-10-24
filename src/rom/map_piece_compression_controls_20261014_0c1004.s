.setcpu "65816"
.segment "CODE"
.org $1004
map_control_0c1004:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
