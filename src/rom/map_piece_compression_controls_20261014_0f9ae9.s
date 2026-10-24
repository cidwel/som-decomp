.setcpu "65816"
.segment "CODE"
.org $9AE9
map_control_0f9ae9:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
