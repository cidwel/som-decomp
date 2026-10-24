.setcpu "65816"
.segment "CODE"
.org $8A66
map_control_0f8a66:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
