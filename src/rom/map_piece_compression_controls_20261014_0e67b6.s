.setcpu "65816"
.segment "CODE"
.org $67B6
map_control_0e67b6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
