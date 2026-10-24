.setcpu "65816"
.segment "CODE"
.org $16B3
map_control_0e16b3:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
