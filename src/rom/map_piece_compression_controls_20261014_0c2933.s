.setcpu "65816"
.segment "CODE"
.org $2933
map_control_0c2933:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
