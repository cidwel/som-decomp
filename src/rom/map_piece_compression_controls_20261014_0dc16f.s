.setcpu "65816"
.segment "CODE"
.org $C16F
map_control_0dc16f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
