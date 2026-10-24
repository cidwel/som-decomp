.setcpu "65816"
.segment "CODE"
.org $10EC
map_control_0d10ec:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
