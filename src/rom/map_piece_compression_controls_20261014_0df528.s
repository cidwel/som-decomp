.setcpu "65816"
.segment "CODE"
.org $F528
map_control_0df528:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
