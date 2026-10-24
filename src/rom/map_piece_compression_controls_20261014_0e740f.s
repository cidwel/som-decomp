.setcpu "65816"
.segment "CODE"
.org $740F
map_control_0e740f:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
