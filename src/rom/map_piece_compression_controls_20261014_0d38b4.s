.setcpu "65816"
.segment "CODE"
.org $38B4
map_control_0d38b4:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
