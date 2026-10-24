.setcpu "65816"
.segment "CODE"
.org $4B3A
map_control_0f4b3a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
