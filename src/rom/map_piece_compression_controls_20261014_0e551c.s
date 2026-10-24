.setcpu "65816"
.segment "CODE"
.org $551C
map_control_0e551c:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
