.setcpu "65816"
.segment "CODE"
.org $FA23
map_control_0ffa23:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
