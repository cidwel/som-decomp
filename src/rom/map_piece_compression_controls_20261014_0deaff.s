.setcpu "65816"
.segment "CODE"
.org $EAFF
map_control_0deaff:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
