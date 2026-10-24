.setcpu "65816"
.segment "CODE"
.org $2B26
map_control_0f2b26:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
