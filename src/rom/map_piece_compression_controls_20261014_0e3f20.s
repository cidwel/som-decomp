.setcpu "65816"
.segment "CODE"
.org $3F20
map_control_0e3f20:
    .byte $CA ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
