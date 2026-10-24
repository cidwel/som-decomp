.setcpu "65816"
.segment "CODE"
.org $FF7F
map_control_0eff7f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
