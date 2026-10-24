.setcpu "65816"
.segment "CODE"
.org $4BFC
map_control_0f4bfc:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
