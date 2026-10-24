.setcpu "65816"
.segment "CODE"
.org $CD9C
map_control_0dcd9c:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
