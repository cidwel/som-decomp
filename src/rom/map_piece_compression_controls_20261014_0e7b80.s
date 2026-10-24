.setcpu "65816"
.segment "CODE"
.org $7B80
map_control_0e7b80:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
