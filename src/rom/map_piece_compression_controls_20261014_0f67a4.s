.setcpu "65816"
.segment "CODE"
.org $67A4
map_control_0f67a4:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
