.setcpu "65816"
.segment "CODE"
.org $0C52
map_control_0d0c52:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E1 ; previous-row copy count
