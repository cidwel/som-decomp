.setcpu "65816"
.segment "CODE"
.org $7A66
map_control_0f7a66:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
