.setcpu "65816"
.segment "CODE"
.org $4097
map_control_0d4097:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
