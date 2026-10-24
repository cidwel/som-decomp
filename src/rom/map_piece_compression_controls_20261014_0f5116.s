.setcpu "65816"
.segment "CODE"
.org $5116
map_control_0f5116:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
