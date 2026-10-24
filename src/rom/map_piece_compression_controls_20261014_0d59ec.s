.setcpu "65816"
.segment "CODE"
.org $59EC
map_control_0d59ec:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
