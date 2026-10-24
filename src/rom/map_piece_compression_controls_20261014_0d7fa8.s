.setcpu "65816"
.segment "CODE"
.org $7FA8
map_control_0d7fa8:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
