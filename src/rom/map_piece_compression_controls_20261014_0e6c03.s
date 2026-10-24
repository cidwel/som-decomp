.setcpu "65816"
.segment "CODE"
.org $6C03
map_control_0e6c03:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
