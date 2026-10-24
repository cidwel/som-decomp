.setcpu "65816"
.segment "CODE"
.org $1F3C
map_control_0e1f3c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
