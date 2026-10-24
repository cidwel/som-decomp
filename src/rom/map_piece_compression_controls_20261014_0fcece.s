.setcpu "65816"
.segment "CODE"
.org $CECE
map_control_0fcece:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
