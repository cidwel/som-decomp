.setcpu "65816"
.segment "CODE"
.org $7E31
map_control_0c7e31:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
