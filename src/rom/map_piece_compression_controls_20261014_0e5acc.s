.setcpu "65816"
.segment "CODE"
.org $5ACC
map_control_0e5acc:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
