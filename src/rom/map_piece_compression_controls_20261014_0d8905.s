.setcpu "65816"
.segment "CODE"
.org $8905
map_control_0d8905:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
