.setcpu "65816"
.segment "CODE"
.org $01BE
map_control_0e01be:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
