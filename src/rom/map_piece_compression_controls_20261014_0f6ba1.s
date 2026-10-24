.setcpu "65816"
.segment "CODE"
.org $6BA1
map_control_0f6ba1:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
