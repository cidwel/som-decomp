.setcpu "65816"
.segment "CODE"
.org $4FA1
map_control_0f4fa1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
