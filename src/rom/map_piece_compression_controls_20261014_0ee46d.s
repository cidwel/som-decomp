.setcpu "65816"
.segment "CODE"
.org $E46D
map_control_0ee46d:
    .byte $F2 ; progressive-copy count
    .byte $C3 ; same-value copy count/distance
