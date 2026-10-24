.setcpu "65816"
.segment "CODE"
.org $15AA
map_control_0d15aa:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
