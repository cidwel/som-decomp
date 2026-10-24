.setcpu "65816"
.segment "CODE"
.org $41CB
map_control_0c41cb:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $3D ; distance low bit/count
