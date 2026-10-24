.setcpu "65816"
.segment "CODE"
.org $AC21
map_control_0eac21:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
