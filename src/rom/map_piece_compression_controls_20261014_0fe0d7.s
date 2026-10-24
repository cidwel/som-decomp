.setcpu "65816"
.segment "CODE"
.org $E0D7
map_control_0fe0d7:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
