.setcpu "65816"
.segment "CODE"
.org $7881
map_control_0d7881:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
