.setcpu "65816"
.segment "CODE"
.org $FF1F
map_control_0eff1f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
