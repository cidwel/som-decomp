.setcpu "65816"
.segment "CODE"
.org $CBD5
map_control_0ecbd5:
    .byte $C4 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
