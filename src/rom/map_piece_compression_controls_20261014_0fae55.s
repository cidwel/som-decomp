.setcpu "65816"
.segment "CODE"
.org $AE55
map_control_0fae55:
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
