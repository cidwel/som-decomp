.setcpu "65816"
.segment "CODE"
.org $E7B2
map_control_0de7b2:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
