.setcpu "65816"
.segment "CODE"
.org $F04F
map_control_0df04f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
