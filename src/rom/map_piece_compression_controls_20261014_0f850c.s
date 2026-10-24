.setcpu "65816"
.segment "CODE"
.org $850C
map_control_0f850c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
