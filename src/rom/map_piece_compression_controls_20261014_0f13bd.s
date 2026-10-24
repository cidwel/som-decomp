.setcpu "65816"
.segment "CODE"
.org $13BD
map_control_0f13bd:
    .byte $C2 ; same-value copy count/distance
