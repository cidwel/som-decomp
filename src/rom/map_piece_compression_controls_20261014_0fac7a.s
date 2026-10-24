.setcpu "65816"
.segment "CODE"
.org $AC7A
map_control_0fac7a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
