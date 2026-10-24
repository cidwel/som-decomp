.setcpu "65816"
.segment "CODE"
.org $CD33
map_control_0fcd33:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
