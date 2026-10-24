.setcpu "65816"
.segment "CODE"
.org $2DE1
map_control_0f2de1:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
