.setcpu "65816"
.segment "CODE"
.org $9678
map_control_0f9678:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
