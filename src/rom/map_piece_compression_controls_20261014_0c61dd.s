.setcpu "65816"
.segment "CODE"
.org $61DD
map_control_0c61dd:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
