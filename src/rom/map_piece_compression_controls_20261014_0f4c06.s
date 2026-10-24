.setcpu "65816"
.segment "CODE"
.org $4C06
map_control_0f4c06:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
