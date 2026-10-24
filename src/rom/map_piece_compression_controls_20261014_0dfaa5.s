.setcpu "65816"
.segment "CODE"
.org $FAA5
map_control_0dfaa5:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
