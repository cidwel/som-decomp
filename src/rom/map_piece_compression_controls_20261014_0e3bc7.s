.setcpu "65816"
.segment "CODE"
.org $3BC7
map_control_0e3bc7:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
