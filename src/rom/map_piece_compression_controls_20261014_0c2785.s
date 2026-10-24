.setcpu "65816"
.segment "CODE"
.org $2785
map_control_0c2785:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
