.setcpu "65816"
.segment "CODE"
.org $04ED
map_control_0f04ed:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
