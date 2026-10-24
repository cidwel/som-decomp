.setcpu "65816"
.segment "CODE"
.org $492D
map_control_0f492d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
