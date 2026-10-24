.setcpu "65816"
.segment "CODE"
.org $2F58
map_control_0f2f58:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
