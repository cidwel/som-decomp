.setcpu "65816"
.segment "CODE"
.org $4875
map_control_0f4875:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
