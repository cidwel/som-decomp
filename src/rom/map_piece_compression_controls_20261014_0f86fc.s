.setcpu "65816"
.segment "CODE"
.org $86FC
map_control_0f86fc:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
