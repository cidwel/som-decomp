.setcpu "65816"
.segment "CODE"
.org $0766
map_control_0f0766:
    .byte $F1 ; progressive-copy count
    .byte $D4 ; same-value copy count/distance
