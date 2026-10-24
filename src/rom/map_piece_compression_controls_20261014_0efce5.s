.setcpu "65816"
.segment "CODE"
.org $FCE5
map_control_0efce5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
