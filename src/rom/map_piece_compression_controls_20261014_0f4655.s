.setcpu "65816"
.segment "CODE"
.org $4655
map_control_0f4655:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
