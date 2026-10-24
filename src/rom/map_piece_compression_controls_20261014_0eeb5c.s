.setcpu "65816"
.segment "CODE"
.org $EB5C
map_control_0eeb5c:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
