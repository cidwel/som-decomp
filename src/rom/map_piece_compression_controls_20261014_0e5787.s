.setcpu "65816"
.segment "CODE"
.org $5787
map_control_0e5787:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
