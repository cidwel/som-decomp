.setcpu "65816"
.segment "CODE"
.org $1043
map_control_0d1043:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
