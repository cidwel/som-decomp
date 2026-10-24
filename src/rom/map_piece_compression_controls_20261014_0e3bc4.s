.setcpu "65816"
.segment "CODE"
.org $3BC4
map_control_0e3bc4:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
