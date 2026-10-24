.setcpu "65816"
.segment "CODE"
.org $F52C
map_control_0df52c:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
