.setcpu "65816"
.segment "CODE"
.org $51D1
map_control_0e51d1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
