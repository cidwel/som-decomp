.setcpu "65816"
.segment "CODE"
.org $7F22
map_control_0c7f22:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
