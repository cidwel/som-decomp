.setcpu "65816"
.segment "CODE"
.org $8205
map_control_0f8205:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
