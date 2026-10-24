.setcpu "65816"
.segment "CODE"
.org $5F15
map_control_0f5f15:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
