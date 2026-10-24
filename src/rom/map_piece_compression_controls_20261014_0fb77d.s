.setcpu "65816"
.segment "CODE"
.org $B77D
map_control_0fb77d:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
