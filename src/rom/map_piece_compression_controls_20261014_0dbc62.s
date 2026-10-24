.setcpu "65816"
.segment "CODE"
.org $BC62
map_control_0dbc62:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
