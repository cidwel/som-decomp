.setcpu "65816"
.segment "CODE"
.org $BDC8
map_control_0dbdc8:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
