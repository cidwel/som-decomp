.setcpu "65816"
.segment "CODE"
.org $9497
map_control_0f9497:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
