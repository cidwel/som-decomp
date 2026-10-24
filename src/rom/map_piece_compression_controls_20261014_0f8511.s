.setcpu "65816"
.segment "CODE"
.org $8511
map_control_0f8511:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
