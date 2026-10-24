.setcpu "65816"
.segment "CODE"
.org $6414
map_control_0f6414:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
