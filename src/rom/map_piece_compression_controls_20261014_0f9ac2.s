.setcpu "65816"
.segment "CODE"
.org $9AC2
map_control_0f9ac2:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
