.setcpu "65816"
.segment "CODE"
.org $73E9
map_control_0f73e9:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
