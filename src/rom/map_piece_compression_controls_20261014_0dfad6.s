.setcpu "65816"
.segment "CODE"
.org $FAD6
map_control_0dfad6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
