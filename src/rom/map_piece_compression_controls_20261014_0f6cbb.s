.setcpu "65816"
.segment "CODE"
.org $6CBB
map_control_0f6cbb:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
