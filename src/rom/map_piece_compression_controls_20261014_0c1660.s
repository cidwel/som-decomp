.setcpu "65816"
.segment "CODE"
.org $1660
map_control_0c1660:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
