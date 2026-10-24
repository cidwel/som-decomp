.setcpu "65816"
.segment "CODE"
.org $3807
map_control_0f3807:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
