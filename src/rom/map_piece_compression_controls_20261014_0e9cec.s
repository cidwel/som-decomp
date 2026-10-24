.setcpu "65816"
.segment "CODE"
.org $9CEC
map_control_0e9cec:
    .byte $D4 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
