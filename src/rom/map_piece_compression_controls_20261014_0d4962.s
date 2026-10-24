.setcpu "65816"
.segment "CODE"
.org $4962
map_control_0d4962:
    .byte $E0 ; previous-row copy escape
    .byte $DD ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5F ; row-distance/count
