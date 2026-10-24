.setcpu "65816"
.segment "CODE"
.org $3EF8
map_control_0f3ef8:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
