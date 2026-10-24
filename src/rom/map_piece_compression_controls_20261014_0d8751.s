.setcpu "65816"
.segment "CODE"
.org $8751
map_control_0d8751:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
