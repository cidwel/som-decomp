.setcpu "65816"
.segment "CODE"
.org $2DF8
map_control_0d2df8:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
