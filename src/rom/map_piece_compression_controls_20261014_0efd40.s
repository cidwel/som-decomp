.setcpu "65816"
.segment "CODE"
.org $FD40
map_control_0efd40:
    .byte $D7 ; same-value copy count/distance
    .byte $F4 ; progressive-copy count
