.setcpu "65816"
.segment "CODE"
.org $1694
map_control_0f1694:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
