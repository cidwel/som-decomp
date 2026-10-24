.setcpu "65816"
.segment "CODE"
.org $9C24
map_control_0f9c24:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
