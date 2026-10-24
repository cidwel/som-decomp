.setcpu "65816"
.segment "CODE"
.org $9928
map_control_0f9928:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
