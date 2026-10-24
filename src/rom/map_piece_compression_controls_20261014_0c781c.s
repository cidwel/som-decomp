.setcpu "65816"
.segment "CODE"
.org $781C
map_control_0c781c:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
