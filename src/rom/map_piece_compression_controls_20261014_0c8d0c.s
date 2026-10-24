.setcpu "65816"
.segment "CODE"
.org $8D0C
map_control_0c8d0c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
