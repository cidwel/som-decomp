.setcpu "65816"
.segment "CODE"
.org $EFD5
map_control_0defd5:
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
