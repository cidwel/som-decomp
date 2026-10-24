.setcpu "65816"
.segment "CODE"
.org $3105
map_control_0f3105:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
