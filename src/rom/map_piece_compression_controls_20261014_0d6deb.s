.setcpu "65816"
.segment "CODE"
.org $6DEB
map_control_0d6deb:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
