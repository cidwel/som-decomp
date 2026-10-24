.setcpu "65816"
.segment "CODE"
.org $4576
map_control_0f4576:
    .byte $E0 ; previous-row copy escape
    .byte $4C ; row-distance/count
