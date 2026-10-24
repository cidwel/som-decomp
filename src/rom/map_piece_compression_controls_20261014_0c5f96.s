.setcpu "65816"
.segment "CODE"
.org $5F96
map_control_0c5f96:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
