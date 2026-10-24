.setcpu "65816"
.segment "CODE"
.org $CA36
map_control_0eca36:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
