.setcpu "65816"
.segment "CODE"
.org $6638
map_control_0f6638:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
