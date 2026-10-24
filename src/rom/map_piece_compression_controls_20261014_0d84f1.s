.setcpu "65816"
.segment "CODE"
.org $84F1
map_control_0d84f1:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
