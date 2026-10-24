.setcpu "65816"
.segment "CODE"
.org $3C16
map_control_0f3c16:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
