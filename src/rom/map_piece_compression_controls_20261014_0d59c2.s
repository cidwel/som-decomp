.setcpu "65816"
.segment "CODE"
.org $59C2
map_control_0d59c2:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
