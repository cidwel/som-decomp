.setcpu "65816"
.segment "CODE"
.org $8500
map_control_0c8500:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
