.setcpu "65816"
.segment "CODE"
.org $4766
map_control_0c4766:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
