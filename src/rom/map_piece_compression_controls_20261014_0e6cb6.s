.setcpu "65816"
.segment "CODE"
.org $6CB6
map_control_0e6cb6:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
