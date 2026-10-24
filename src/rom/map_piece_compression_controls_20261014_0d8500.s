.setcpu "65816"
.segment "CODE"
.org $8500
map_control_0d8500:
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
