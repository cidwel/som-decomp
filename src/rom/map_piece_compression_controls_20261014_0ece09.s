.setcpu "65816"
.segment "CODE"
.org $CE09
map_control_0ece09:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
