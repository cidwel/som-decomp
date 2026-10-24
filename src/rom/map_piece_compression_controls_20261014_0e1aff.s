.setcpu "65816"
.segment "CODE"
.org $1AFF
map_control_0e1aff:
    .byte $DB ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
