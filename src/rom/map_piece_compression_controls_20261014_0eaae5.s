.setcpu "65816"
.segment "CODE"
.org $AAE5
map_control_0eaae5:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
