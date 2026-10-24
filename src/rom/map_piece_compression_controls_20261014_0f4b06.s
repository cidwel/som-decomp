.setcpu "65816"
.segment "CODE"
.org $4B06
map_control_0f4b06:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
