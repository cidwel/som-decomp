.setcpu "65816"
.segment "CODE"
.org $1570
map_control_0f1570:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
