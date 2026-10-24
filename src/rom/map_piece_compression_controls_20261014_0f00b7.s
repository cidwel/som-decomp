.setcpu "65816"
.segment "CODE"
.org $00B7
map_control_0f00b7:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
