.setcpu "65816"
.segment "CODE"
.org $FF68
map_control_0dff68:
    .byte $C9 ; same-value copy count/distance
