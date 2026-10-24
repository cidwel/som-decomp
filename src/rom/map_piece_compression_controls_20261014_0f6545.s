.setcpu "65816"
.segment "CODE"
.org $6545
map_control_0f6545:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
