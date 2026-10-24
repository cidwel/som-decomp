.setcpu "65816"
.segment "CODE"
.org $51E8
map_control_0d51e8:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
