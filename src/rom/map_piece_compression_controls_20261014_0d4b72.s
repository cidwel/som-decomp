.setcpu "65816"
.segment "CODE"
.org $4B72
map_control_0d4b72:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
