.setcpu "65816"
.segment "CODE"
.org $D029
map_control_0fd029:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $70 ; distance low bit/count
