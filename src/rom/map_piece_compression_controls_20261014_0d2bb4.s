.setcpu "65816"
.segment "CODE"
.org $2BB4
map_control_0d2bb4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
