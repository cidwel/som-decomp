.setcpu "65816"
.segment "CODE"
.org $AD2B
map_control_0ead2b:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
