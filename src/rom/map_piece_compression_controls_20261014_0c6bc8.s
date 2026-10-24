.setcpu "65816"
.segment "CODE"
.org $6BC8
map_control_0c6bc8:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
