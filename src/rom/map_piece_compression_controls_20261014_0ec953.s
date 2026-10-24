.setcpu "65816"
.segment "CODE"
.org $C953
map_control_0ec953:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
