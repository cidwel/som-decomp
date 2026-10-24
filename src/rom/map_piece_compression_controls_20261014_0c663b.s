.setcpu "65816"
.segment "CODE"
.org $663B
map_control_0c663b:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
