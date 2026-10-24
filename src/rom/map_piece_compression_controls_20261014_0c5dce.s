.setcpu "65816"
.segment "CODE"
.org $5DCE
map_control_0c5dce:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
