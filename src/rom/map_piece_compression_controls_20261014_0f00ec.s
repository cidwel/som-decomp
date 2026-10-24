.setcpu "65816"
.segment "CODE"
.org $00EC
map_control_0f00ec:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
