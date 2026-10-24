.setcpu "65816"
.segment "CODE"
.org $04D4
map_control_0f04d4:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
