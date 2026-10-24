.setcpu "65816"
.segment "CODE"
.org $CE4F
map_control_0ece4f:
    .byte $E0 ; previous-row copy escape
    .byte $C3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
