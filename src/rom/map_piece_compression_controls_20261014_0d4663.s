.setcpu "65816"
.segment "CODE"
.org $4663
map_control_0d4663:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
