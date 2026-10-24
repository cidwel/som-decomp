.setcpu "65816"
.segment "CODE"
.org $FC02
map_control_0dfc02:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
