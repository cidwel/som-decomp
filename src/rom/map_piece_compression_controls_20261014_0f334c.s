.setcpu "65816"
.segment "CODE"
.org $334C
map_control_0f334c:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
