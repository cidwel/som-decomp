.setcpu "65816"
.segment "CODE"
.org $41BE
map_control_0c41be:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $3D ; distance low bit/count
