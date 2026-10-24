.setcpu "65816"
.segment "CODE"
.org $762A
map_control_0e762a:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
