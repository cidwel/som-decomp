.setcpu "65816"
.segment "CODE"
.org $6959
map_control_0f6959:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
