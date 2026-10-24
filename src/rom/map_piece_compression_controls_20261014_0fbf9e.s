.setcpu "65816"
.segment "CODE"
.org $BF9E
map_control_0fbf9e:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
