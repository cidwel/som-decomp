.setcpu "65816"
.segment "CODE"
.org $7743
map_control_0e7743:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
