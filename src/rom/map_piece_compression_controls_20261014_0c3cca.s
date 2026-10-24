.setcpu "65816"
.segment "CODE"
.org $3CCA
map_control_0c3cca:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
