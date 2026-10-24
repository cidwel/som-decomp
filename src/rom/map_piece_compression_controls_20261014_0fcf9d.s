.setcpu "65816"
.segment "CODE"
.org $CF9D
map_control_0fcf9d:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
