.setcpu "65816"
.segment "CODE"
.org $45E9
map_control_0f45e9:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
