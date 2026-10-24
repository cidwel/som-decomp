.setcpu "65816"
.segment "CODE"
.org $22B9
map_control_0d22b9:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
