.setcpu "65816"
.segment "CODE"
.org $9BC7
map_control_0f9bc7:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
