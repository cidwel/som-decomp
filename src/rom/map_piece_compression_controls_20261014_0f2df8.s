.setcpu "65816"
.segment "CODE"
.org $2DF8
map_control_0f2df8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
