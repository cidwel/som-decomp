.setcpu "65816"
.segment "CODE"
.org $8271
map_control_0d8271:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
