.setcpu "65816"
.segment "CODE"
.org $5DCF
map_control_0f5dcf:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
