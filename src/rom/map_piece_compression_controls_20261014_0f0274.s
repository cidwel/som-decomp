.setcpu "65816"
.segment "CODE"
.org $0274
map_control_0f0274:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
