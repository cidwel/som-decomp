.setcpu "65816"
.segment "CODE"
.org $73E2
map_control_0f73e2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
