.setcpu "65816"
.segment "CODE"
.org $EC33
map_control_0eec33:
    .byte $CF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
