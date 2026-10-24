.setcpu "65816"
.segment "CODE"
.org $8AE5
map_control_0f8ae5:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
