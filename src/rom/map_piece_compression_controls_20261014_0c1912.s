.setcpu "65816"
.segment "CODE"
.org $1912
map_control_0c1912:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
