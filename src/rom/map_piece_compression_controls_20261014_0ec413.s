.setcpu "65816"
.segment "CODE"
.org $C413
map_control_0ec413:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
