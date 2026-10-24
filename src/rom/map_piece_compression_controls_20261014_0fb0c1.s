.setcpu "65816"
.segment "CODE"
.org $B0C1
map_control_0fb0c1:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
