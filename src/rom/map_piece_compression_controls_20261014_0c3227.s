.setcpu "65816"
.segment "CODE"
.org $3227
map_control_0c3227:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E1 ; previous-row copy count
