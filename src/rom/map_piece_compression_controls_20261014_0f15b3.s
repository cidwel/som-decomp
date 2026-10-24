.setcpu "65816"
.segment "CODE"
.org $15B3
map_control_0f15b3:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
