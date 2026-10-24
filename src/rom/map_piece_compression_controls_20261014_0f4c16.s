.setcpu "65816"
.segment "CODE"
.org $4C16
map_control_0f4c16:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
