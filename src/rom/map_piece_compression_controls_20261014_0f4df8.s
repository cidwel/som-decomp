.setcpu "65816"
.segment "CODE"
.org $4DF8
map_control_0f4df8:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
