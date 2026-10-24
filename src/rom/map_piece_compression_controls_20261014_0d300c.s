.setcpu "65816"
.segment "CODE"
.org $300C
map_control_0d300c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
