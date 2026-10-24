.setcpu "65816"
.segment "CODE"
.org $6055
map_control_0f6055:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
