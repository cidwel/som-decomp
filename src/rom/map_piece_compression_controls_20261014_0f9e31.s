.setcpu "65816"
.segment "CODE"
.org $9E31
map_control_0f9e31:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
