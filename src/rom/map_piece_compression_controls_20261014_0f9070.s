.setcpu "65816"
.segment "CODE"
.org $9070
map_control_0f9070:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C4 ; same-value copy count/distance
