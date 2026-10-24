.setcpu "65816"
.segment "CODE"
.org $6BA7
map_control_0f6ba7:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
