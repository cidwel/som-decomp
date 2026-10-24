.setcpu "65816"
.segment "CODE"
.org $BA9F
map_control_0dba9f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
