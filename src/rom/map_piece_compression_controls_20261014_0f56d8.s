.setcpu "65816"
.segment "CODE"
.org $56D8
map_control_0f56d8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
