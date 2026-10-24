.setcpu "65816"
.segment "CODE"
.org $CA63
map_control_0eca63:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
