.setcpu "65816"
.segment "CODE"
.org $2A88
map_control_0e2a88:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
