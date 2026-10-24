.setcpu "65816"
.segment "CODE"
.org $456D
map_control_0c456d:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
