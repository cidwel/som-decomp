.setcpu "65816"
.segment "CODE"
.org $9850
map_control_0f9850:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
