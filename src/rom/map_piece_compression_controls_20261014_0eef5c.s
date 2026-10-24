.setcpu "65816"
.segment "CODE"
.org $EF5C
map_control_0eef5c:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
