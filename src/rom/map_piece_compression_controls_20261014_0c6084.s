.setcpu "65816"
.segment "CODE"
.org $6084
map_control_0c6084:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
