.setcpu "65816"
.segment "CODE"
.org $C680
map_control_0dc680:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
