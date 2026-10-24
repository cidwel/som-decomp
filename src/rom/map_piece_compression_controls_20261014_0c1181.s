.setcpu "65816"
.segment "CODE"
.org $1181
map_control_0c1181:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
