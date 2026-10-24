.setcpu "65816"
.segment "CODE"
.org $4AFF
map_control_0f4aff:
    .byte $C2 ; same-value copy count/distance
