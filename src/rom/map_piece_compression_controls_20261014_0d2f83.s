.setcpu "65816"
.segment "CODE"
.org $2F83
map_control_0d2f83:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
