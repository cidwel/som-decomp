.setcpu "65816"
.segment "CODE"
.org $8CE7
map_control_0e8ce7:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
