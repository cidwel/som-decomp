.setcpu "65816"
.segment "CODE"
.org $79A9
map_control_0e79a9:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
