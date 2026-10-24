.setcpu "65816"
.segment "CODE"
.org $BF1A
map_control_0fbf1a:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $D5 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E7 ; previous-row copy count
