.setcpu "65816"
.segment "CODE"
.org $C5D1
map_control_0ec5d1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
