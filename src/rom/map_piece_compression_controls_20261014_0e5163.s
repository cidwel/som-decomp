.setcpu "65816"
.segment "CODE"
.org $5163
map_control_0e5163:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
