.setcpu "65816"
.segment "CODE"
.org $4CA1
map_control_0f4ca1:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
