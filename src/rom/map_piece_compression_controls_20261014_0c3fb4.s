.setcpu "65816"
.segment "CODE"
.org $3FB4
map_control_0c3fb4:
    .byte $CF ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
