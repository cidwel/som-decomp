.setcpu "65816"
.segment "CODE"
.org $0856
map_control_0d0856:
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
