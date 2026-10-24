.setcpu "65816"
.segment "CODE"
.org $0916
map_control_0e0916:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
