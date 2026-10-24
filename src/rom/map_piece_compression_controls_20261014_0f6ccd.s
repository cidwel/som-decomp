.setcpu "65816"
.segment "CODE"
.org $6CCD
map_control_0f6ccd:
    .byte $F2 ; progressive-copy count
    .byte $DB ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $26 ; distance low bit/count
