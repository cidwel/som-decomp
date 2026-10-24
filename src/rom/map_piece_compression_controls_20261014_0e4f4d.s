.setcpu "65816"
.segment "CODE"
.org $4F4D
map_control_0e4f4d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
