.setcpu "65816"
.segment "CODE"
.org $B82A
map_control_0fb82a:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
