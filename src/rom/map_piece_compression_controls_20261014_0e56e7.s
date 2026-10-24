.setcpu "65816"
.segment "CODE"
.org $56E7
map_control_0e56e7:
    .byte $F2 ; progressive-copy count
    .byte $C5 ; same-value copy count/distance
