.setcpu "65816"
.segment "CODE"
.org $05B8
map_control_0e05b8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
