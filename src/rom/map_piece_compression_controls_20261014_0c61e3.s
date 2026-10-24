.setcpu "65816"
.segment "CODE"
.org $61E3
map_control_0c61e3:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
