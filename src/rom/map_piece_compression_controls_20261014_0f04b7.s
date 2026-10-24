.setcpu "65816"
.segment "CODE"
.org $04B7
map_control_0f04b7:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
