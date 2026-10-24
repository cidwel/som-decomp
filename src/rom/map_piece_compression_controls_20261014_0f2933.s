.setcpu "65816"
.segment "CODE"
.org $2933
map_control_0f2933:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
