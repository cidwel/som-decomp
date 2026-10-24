.setcpu "65816"
.segment "CODE"
.org $4DB5
map_control_0f4db5:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
