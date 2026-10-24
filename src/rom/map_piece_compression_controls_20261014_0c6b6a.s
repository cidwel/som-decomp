.setcpu "65816"
.segment "CODE"
.org $6B6A
map_control_0c6b6a:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $E3 ; previous-row copy count
