.setcpu "65816"
.segment "CODE"
.org $5128
map_control_0e5128:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
