.setcpu "65816"
.segment "CODE"
.org $3ED2
map_control_0e3ed2:
    .byte $D2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
