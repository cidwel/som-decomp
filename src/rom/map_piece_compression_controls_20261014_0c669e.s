.setcpu "65816"
.segment "CODE"
.org $669E
map_control_0c669e:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
