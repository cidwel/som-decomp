.setcpu "65816"
.segment "CODE"
.org $ECEC
map_control_0eecec:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
