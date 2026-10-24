.setcpu "65816"
.segment "CODE"
.org $7CD4
map_control_0e7cd4:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
