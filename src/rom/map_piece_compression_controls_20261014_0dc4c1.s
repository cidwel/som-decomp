.setcpu "65816"
.segment "CODE"
.org $C4C1
map_control_0dc4c1:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
