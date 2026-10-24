.setcpu "65816"
.segment "CODE"
.org $1922
map_control_0c1922:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
