.setcpu "65816"
.segment "CODE"
.org $D109
map_control_0ed109:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
