.setcpu "65816"
.segment "CODE"
.org $EFD8
map_control_0defd8:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
