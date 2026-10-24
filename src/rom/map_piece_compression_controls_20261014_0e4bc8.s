.setcpu "65816"
.segment "CODE"
.org $4BC8
map_control_0e4bc8:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
