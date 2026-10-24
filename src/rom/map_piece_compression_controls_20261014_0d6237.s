.setcpu "65816"
.segment "CODE"
.org $6237
map_control_0d6237:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
