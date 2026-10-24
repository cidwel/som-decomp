.setcpu "65816"
.segment "CODE"
.org $5C16
map_control_0f5c16:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
