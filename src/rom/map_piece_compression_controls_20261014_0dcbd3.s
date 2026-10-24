.setcpu "65816"
.segment "CODE"
.org $CBD3
map_control_0dcbd3:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
