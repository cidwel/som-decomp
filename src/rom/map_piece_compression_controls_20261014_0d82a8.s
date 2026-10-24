.setcpu "65816"
.segment "CODE"
.org $82A8
map_control_0d82a8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
