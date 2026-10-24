.setcpu "65816"
.segment "CODE"
.org $8718
map_control_0f8718:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $CB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
