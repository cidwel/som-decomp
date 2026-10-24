.setcpu "65816"
.segment "CODE"
.org $EAD4
map_control_0eead4:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
