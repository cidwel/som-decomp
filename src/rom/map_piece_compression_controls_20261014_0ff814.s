.setcpu "65816"
.segment "CODE"
.org $F814
map_control_0ff814:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
