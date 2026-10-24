.setcpu "65816"
.segment "CODE"
.org $7F96
map_control_0f7f96:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
