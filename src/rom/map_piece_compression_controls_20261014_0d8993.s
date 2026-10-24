.setcpu "65816"
.segment "CODE"
.org $8993
map_control_0d8993:
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
