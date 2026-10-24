.setcpu "65816"
.segment "CODE"
.org $7986
map_control_0d7986:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
