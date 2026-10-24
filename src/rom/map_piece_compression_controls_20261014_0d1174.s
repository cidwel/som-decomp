.setcpu "65816"
.segment "CODE"
.org $1174
map_control_0d1174:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
