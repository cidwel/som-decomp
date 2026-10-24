.setcpu "65816"
.segment "CODE"
.org $D2B1
map_control_0fd2b1:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
