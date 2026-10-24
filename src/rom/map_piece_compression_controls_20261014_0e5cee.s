.setcpu "65816"
.segment "CODE"
.org $5CEE
map_control_0e5cee:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
