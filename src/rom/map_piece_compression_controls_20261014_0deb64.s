.setcpu "65816"
.segment "CODE"
.org $EB64
map_control_0deb64:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
