.setcpu "65816"
.segment "CODE"
.org $1C2C
map_control_0d1c2c:
    .byte $CC ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
