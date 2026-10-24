.setcpu "65816"
.segment "CODE"
.org $1C9A
map_control_0f1c9a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
