.setcpu "65816"
.segment "CODE"
.org $6BA6
map_control_0c6ba6:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
