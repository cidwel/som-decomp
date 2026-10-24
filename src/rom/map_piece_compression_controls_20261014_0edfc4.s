.setcpu "65816"
.segment "CODE"
.org $DFC4
map_control_0edfc4:
    .byte $E8 ; backreference distance high bits
    .byte $48 ; distance low bit/count
