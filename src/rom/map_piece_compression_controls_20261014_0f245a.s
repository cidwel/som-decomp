.setcpu "65816"
.segment "CODE"
.org $245A
map_control_0f245a:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
