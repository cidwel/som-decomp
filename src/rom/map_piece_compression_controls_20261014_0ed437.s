.setcpu "65816"
.segment "CODE"
.org $D437
map_control_0ed437:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
