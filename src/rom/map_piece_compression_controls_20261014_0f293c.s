.setcpu "65816"
.segment "CODE"
.org $293C
map_control_0f293c:
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
