.setcpu "65816"
.segment "CODE"
.org $54DE
map_control_0f54de:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
