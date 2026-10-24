.setcpu "65816"
.segment "CODE"
.org $2BC3
map_control_0d2bc3:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
