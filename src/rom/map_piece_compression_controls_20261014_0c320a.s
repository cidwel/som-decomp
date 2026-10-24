.setcpu "65816"
.segment "CODE"
.org $320A
map_control_0c320a:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
