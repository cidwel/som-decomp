.setcpu "65816"
.segment "CODE"
.org $5F94
map_control_0e5f94:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
