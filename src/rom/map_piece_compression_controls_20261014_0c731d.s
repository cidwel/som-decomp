.setcpu "65816"
.segment "CODE"
.org $731D
map_control_0c731d:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
