.setcpu "65816"
.segment "CODE"
.org $BDE0
map_control_0ebde0:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
